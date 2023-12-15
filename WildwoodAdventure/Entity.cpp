/**
* Author: Gavin Zhao
* Assignment: Wildwood Adventure
* Date due: 2023-12-15, 11:59pm
* I pledge that I have completed this assignment without
* collaborating with anyone else, in conformance with the
* NYU School of Engineering Policies and Procedures on
* Academic Misconduct.
**/

#define LOG(argument) std::cout << argument << '\n'
#define GL_SILENCE_DEPRECATION
#define STB_IMAGE_IMPLEMENTATION

#ifdef _WINDOWS
#include <GL/glew.h>
#endif

#define GL_GLEXT_PROTOTYPES 1
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"
#include "Entity.h"

Entity::Entity()
{
    // ––––– PHYSICS ––––– //
    m_position = glm::vec3(0.0f);
    m_velocity = glm::vec3(0.0f);
    m_acceleration = glm::vec3(0.0f);

    // ––––– TRANSLATION ––––– //
    m_movement = glm::vec3(0.0f);
    m_speed = 0;
    m_model_matrix = glm::mat4(1.0f);
}

Entity::~Entity()
{
    delete[] m_animation_up;
    delete[] m_animation_down;
    delete[] m_animation_left;
    delete[] m_animation_right;
    delete[] m_animation_attack_up;
    delete[] m_animation_attack_down;
    delete[] m_animation_attack_left;
    delete[] m_animation_attack_right;
    delete[] m_walking;
    delete[] m_attacking;
}

void Entity::draw_sprite_from_texture_atlas(ShaderProgram* program, GLuint texture_id, int index)
{
    // Step 1: Calculate the UV location of the indexed frame
    float u_coord = (float)(index % m_animation_cols) / (float)m_animation_cols;
    float v_coord = (float)(index / m_animation_cols) / (float)m_animation_rows;

    // Step 2: Calculate its UV size
    float width = 1.0f / (float)m_animation_cols;
    float height = 1.0f / (float)m_animation_rows;

    // Step 3: Just as we have done before, match the texture coordinates to the vertices
    float tex_coords[] =
    {
        u_coord, v_coord + height, u_coord + width, v_coord + height, u_coord + width, v_coord,
        u_coord, v_coord + height, u_coord + width, v_coord, u_coord, v_coord
    };

    float vertices[] =
    {
        -0.5, -0.5, 0.5, -0.5,  0.5, 0.5,
        -0.5, -0.5, 0.5,  0.5, -0.5, 0.5
    };

    // Step 4: And render
    glBindTexture(GL_TEXTURE_2D, texture_id);

    glVertexAttribPointer(program->get_position_attribute(), 2, GL_FLOAT, false, 0, vertices);
    glEnableVertexAttribArray(program->get_position_attribute());

    glVertexAttribPointer(program->get_tex_coordinate_attribute(), 2, GL_FLOAT, false, 0, tex_coords);
    glEnableVertexAttribArray(program->get_tex_coordinate_attribute());

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(program->get_position_attribute());
    glDisableVertexAttribArray(program->get_tex_coordinate_attribute());
}

void Entity::ai_activate(Entity* player)
{
    switch (m_ai_type)
    {
    case WALKER:
        ai_walk();
        break;

    case GUARD:
        ai_guard(player);
        break;
    
    case JUMPER:
        ai_jump(player);
        break;

    default:
        break;
    }
}

void Entity::ai_walk()
{
    switch (m_ai_state){
        case ROAM_RIGHT:
            m_movement = glm::vec3(1.0f, 0.0f, 0.0f);
            if (m_position.x >= m_right_edge) {
                m_ai_state = ROAM_LEFT;
                m_animation_indices = m_walking[LEFT];
            }
            break;
        
        case ROAM_LEFT:
            m_movement = glm::vec3(-1.0f, 0.0f, 0.0f);
            if (m_position.x <= m_left_edge) {
                m_ai_state = ROAM_RIGHT;
                m_animation_indices = m_walking[RIGHT];
            }
            break;
            
        default:
            break;
    }
    
}

void Entity::ai_guard(Entity* player){
    switch (m_ai_state) {
        case IDLE:
            if (glm::distance(m_position, player->get_position()) < 2.5f)
                m_ai_state = WALKING;
            break;

        case WALKING:
            if (glm::distance(m_position, player->get_position()) < 1.5f) {
                m_ai_state = ATTACKING;
                break;
            }
            if (glm::distance(m_position, player->get_position()) > 2.5f || player->m_is_dead) {
                m_ai_state = IDLE;
                m_movement = glm::vec3(0.0f, 0.0f, 0.0f);
                break;
            }
            
            if (abs(m_position.x - player->get_position().x) > abs(m_position.y - player->get_position().y)){
                if (m_position.x > player->get_position().x){
                    m_movement.x = -0.75f;
                    m_animation_indices = m_walking[LEFT];
                }
                else if (m_position.x < player->get_position().x){
                    m_movement.x = 0.75f;
                    m_animation_indices = m_walking[RIGHT];
                }
            }
            else{
                if (m_position.y > player->get_position().y){
                    m_movement.y = -0.75f;
                    m_animation_indices = m_walking[DOWN];
                }
                else if (m_position.y < player->get_position().y){
                    m_movement.y = 0.75f;
                    m_animation_indices = m_walking[UP];
                }
            }
            break;

        case ATTACKING:
            if (player->m_is_dead){
                m_ai_state = IDLE;
                m_movement = glm::vec3(0.0f, 0.0f, 0.0f);
                break;
            }
            if (glm::distance(m_position, player->get_position()) > 2.5f){
                m_ai_state = WALKING;
                break;
            }
            if (abs(m_position.x - player->get_position().x) > abs(m_position.y - player->get_position().y)){
                if (m_position.x > player->get_position().x){
                    m_movement.x = -1.5f;
                    m_animation_indices = m_walking[LEFT];
                }
                else if (m_position.x < player->get_position().x){
                    m_movement.x = 1.5f;
                    m_animation_indices = m_walking[RIGHT];
                }
            }
            else {
                if (m_position.y > player->get_position().y){
                    m_movement.y = -1.5f;
                    m_animation_indices = m_walking[DOWN];
                }
                else if (m_position.y < player->get_position().y){
                    m_movement.y = 1.5f;
                    m_animation_indices = m_walking[UP];
                }
            }
            break;
            
        default:
            break;
    }
}

void Entity::ai_jump(Entity* player){
    switch (m_ai_state) {
        case IDLE:
            if (glm::distance(m_position, player->get_position()) < 3.0f) {
                m_ai_state = JUMPING;
                m_jumping_power = 6.5f;
                break;
            }
            if (m_collided_bottom){
                if (m_curr_jump_time >= m_jump_timer){
                    m_is_jumping = true;
                    m_curr_jump_time = 0;
                }
                else{
                    m_curr_jump_time += 1;
                }
            }
            
            break;
        case JUMPING:
            if (glm::distance(m_position, player->get_position()) >= 4.0f || !player->m_is_active) {
                m_ai_state = IDLE;
                m_jumping_power = 2.5f;
                m_movement = glm::vec3(0.0f, 0.0f, 0.0f);
                break;
            }
            if (m_collided_bottom){
                if (m_curr_jump_time >= m_jump_timer){
                    m_is_jumping = true;
                    m_curr_jump_time = 0;
                }
                else{
                    m_curr_jump_time += 1;
                }
            }
            if (m_position.x > player->get_position().x){
                m_movement = glm::vec3(-0.25f, 0.0f, 0.0f);
            }
            else {
                m_movement = glm::vec3(0.25f, 0.0f, 0.0f);
            }
            break;
        
        default:
            break;
    }
}

int Entity::check_direction(){
    int current_animation = m_animation_indices[m_animation_index];
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (current_animation == m_walking[i][j] || current_animation == m_attacking[i][j]) return i;
        }
    }
    return 0;
}

void Entity::attack(Entity* collidable_entities, int collidable_entity_count){
    for (int i = 0; i < collidable_entity_count; i++){
        Entity* collidable_entity = &collidable_entities[i];
        int direction = check_direction();
        
        if (glm::distance(m_position, collidable_entity->get_position()) < 1.0f){
            if ((direction == LEFT && m_position.x > collidable_entity->get_position().x) ||
                (direction == RIGHT && m_position.x < collidable_entity->get_position().x) ||
                (direction == UP && m_position.y < collidable_entity->get_position().y) ||
                (direction == DOWN && m_position.y > collidable_entity->get_position().y)){
                
                if (!m_hit) {
                    collidable_entity->m_num_lives--;
                    m_hit = true;
                    if (collidable_entity->m_num_lives == 0) collidable_entity->die();
                    else {
                        if (!collidable_entity->m_is_dead) collidable_entity->knockback(direction);
                    }
                }
            }
        }
    }
}

void Entity::knockback(int direction){
    if (direction == LEFT) m_position.x -= 0.75f;
    else if (direction == RIGHT) m_position.x += 0.75f;
    else if (direction == UP) m_position.y += 0.5f;
    else if (direction == DOWN) m_position.y -= 0.5f;
}

void Entity::die(){
    m_animation_frames = m_death_frames;
    m_animation_indices = m_death;
    m_animation_time = 0.0f;
    m_animation_index = 0;
    m_is_dead = true;
    m_movement = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Entity::update(float delta_time, Entity* player, Entity* objects, int object_count, Map* map)
{
    if (!m_is_active) return;
    
    if (m_entity_type == HEART){
        m_model_matrix = glm::mat4(1.0f);
        m_model_matrix = glm::translate(m_model_matrix, m_position);
        m_model_matrix = glm::scale(m_model_matrix, glm::vec3(m_width, m_height, 1.0f));
        return;
    }

    m_collided_top = false;
    m_collided_bottom = false;
    m_collided_left = false;
    m_collided_right = false;
    
    if (m_animation_indices != NULL ){
        if (m_is_dead){
            m_animation_time += delta_time;
            float frames_per_second = 1.25f / SECONDS_PER_FRAME;
            if (m_entity_type == ENEMY) frames_per_second = 0.5f / SECONDS_PER_FRAME;

            if (m_animation_index >= m_animation_frames - 1) {
                m_num_lives--;
                m_revive = true;
                m_animation_indices = m_walking[RIGHT];
                m_animation_index = 0;
                deactivate();
                if (m_entity_type == ENEMY) player->m_enemies_killed++;
            }
            
            if (m_animation_time >= frames_per_second && m_animation_index < m_animation_frames - 1){
                m_animation_time = 0.0f;
                m_animation_index++;
            }
        }
        
        else if (m_begin_attack){
            m_is_attacking = true;
            m_animation_indices = m_attacking[check_direction()];
            m_animation_time = 0.0f;
            m_animation_index = 0;
            m_begin_attack = false;
        }
        else if (m_is_attacking){
            m_animation_time += delta_time;
            float frames_per_second = 0.5f / SECONDS_PER_FRAME;

            if (m_animation_index >= m_animation_frames - 1) {
                m_is_attacking = false;
                m_animation_indices = m_walking[check_direction()];
                m_animation_index = 0;
                m_hit = false;
            }
            
            if (m_animation_time >= frames_per_second && m_animation_index < m_animation_frames - 1){
                m_animation_time = 0.0f;
                m_animation_index++;
            }
        }
        
        
        else if (glm::length(m_movement) != 0)
        {

            m_animation_time += delta_time;
            float frames_per_second = (float)1 / SECONDS_PER_FRAME;

            if (m_animation_time >= frames_per_second)
            {
                m_animation_time = 0.0f;
                m_animation_index++;

                if (m_animation_index >= m_animation_frames)
                {
                    m_animation_index = 0;
                }
            }
        }
    }
    
    if (!m_is_dead){
        m_velocity.x = m_movement.x * m_speed;
        //    m_velocity += m_acceleration * delta_time;
        
        m_velocity.y = m_movement.y * m_speed;
        //    m_velocity += m_acceleration * delta_time;
        
        // We make two calls to our check_collision methods, one for the collidable objects and one for
        // the map.
        m_position.y += m_velocity.y * delta_time;
        check_collision_y(objects, object_count);
        check_collision_y(map);
        
        
        m_position.x += m_velocity.x * delta_time;
        check_collision_x(objects, object_count);
        check_collision_x(map);
    }

    if (m_entity_type == ENEMY && !m_is_dead) ai_activate(player);
    
    if (m_is_jumping)
    {
        m_is_jumping = false;

        m_velocity.y += m_jumping_power;
    }
    
    if (m_entity_type == PLAYER && m_is_attacking) attack(objects, object_count);

    m_model_matrix = glm::mat4(1.0f);
    m_model_matrix = glm::translate(m_model_matrix, m_position);
}

void const Entity::check_collision_y(Entity* collidable_entities, int collidable_entity_count)
{
    for (int i = 0; i < collidable_entity_count; i++)
    {
        Entity* collidable_entity = &collidable_entities[i];
        
        if (!collidable_entity->m_is_dead && check_collision(collidable_entity))
        {
            float y_distance = fabs(m_position.y - collidable_entity->get_position().y);
            float y_overlap = fabs(y_distance - (m_height / 2.0f) - (collidable_entity->get_height() / 2.0f));
            if (m_velocity.y > 0) {
                m_position.y -= y_overlap;
                m_velocity.y = 0;
                m_collided_top = true;
            }
            else if (m_velocity.y < 0) {
                m_position.y += y_overlap;
                m_velocity.y = 0;
                m_collided_bottom = true;
            }
            if (m_collided_bottom || m_collided_top) die();
        }
    }
}

void const Entity::check_collision_x(Entity* collidable_entities, int collidable_entity_count)
{
    for (int i = 0; i < collidable_entity_count; i++)
    {
        Entity* collidable_entity = &collidable_entities[i];

        if (!collidable_entity->m_is_dead && check_collision(collidable_entity))
        {
            float x_distance = fabs(m_position.x - collidable_entity->get_position().x);
            float x_overlap = fabs(x_distance - (m_width / 2.0f) - (collidable_entity->get_width() / 2.0f));
            if (m_velocity.x >= 0) {
                m_position.x -= x_overlap;
                m_velocity.x = 0;
                m_collided_right = true;
            }
            else if (m_velocity.x < 0) {
                m_position.x += x_overlap;
                m_velocity.x = 0;
                m_collided_left = true;
            }
            if (m_collided_left || m_collided_right) die();
            
        }
    }
}


void const Entity::check_collision_y(Map* map)
{
    // Probes for tiles above
    glm::vec3 top = glm::vec3(m_position.x, m_position.y + (m_height / 2), m_position.z);
    glm::vec3 top_left = glm::vec3(m_position.x - (m_width / 2), m_position.y + (m_height / 2), m_position.z);
    glm::vec3 top_right = glm::vec3(m_position.x + (m_width / 2), m_position.y + (m_height / 2), m_position.z);

    // Probes for tiles below
    glm::vec3 bottom = glm::vec3(m_position.x, m_position.y - (m_height / 2), m_position.z);
    glm::vec3 bottom_left = glm::vec3(m_position.x - (m_width / 2), m_position.y - (m_height / 2), m_position.z);
    glm::vec3 bottom_right = glm::vec3(m_position.x + (m_width / 2), m_position.y - (m_height / 2), m_position.z);

    float penetration_x = 0;
    float penetration_y = 0;

    // If the map is solid, check the top three points
    if (map->is_solid(top, &penetration_x, &penetration_y) && m_velocity.y > 0)
    {
        m_position.y -= penetration_y;
        m_velocity.y = 0;
        m_collided_top = true;
    }
    else if (map->is_solid(top_left, &penetration_x, &penetration_y) && m_velocity.y > 0)
    { 
        m_position.y -= penetration_y;
        m_velocity.y = 0;
        m_collided_top = true;
    }
    else if (map->is_solid(top_right, &penetration_x, &penetration_y) && m_velocity.y > 0)
    {
        m_position.y -= penetration_y;
        m_velocity.y = 0;
        m_collided_top = true;
    }

    // And the bottom three points
    if (map->is_solid(bottom, &penetration_x, &penetration_y) && m_velocity.y < 0)
    {
        m_position.y += penetration_y;
        m_velocity.y = 0;
        m_collided_bottom = true;
    }
    else if (map->is_solid(bottom_left, &penetration_x, &penetration_y) && m_velocity.y < 0)
    {
        m_position.y += penetration_y;
        m_velocity.y = 0;
        m_collided_bottom = true;
    }
    else if (map->is_solid(bottom_right, &penetration_x, &penetration_y) && m_velocity.y < 0)
    {
        m_position.y += penetration_y;
        m_velocity.y = 0;
        m_collided_bottom = true;

    }
}

void const Entity::check_collision_x(Map* map)
{
    // Probes for tiles; the x-checking is much simpler
    glm::vec3 left = glm::vec3(m_position.x - (m_width / 2), m_position.y, m_position.z);
    glm::vec3 right = glm::vec3(m_position.x + (m_width / 2), m_position.y, m_position.z);

    float penetration_x = 0;
    float penetration_y = 0;

    if (map->is_solid(left, &penetration_x, &penetration_y) && m_velocity.x < 0)
    {
        m_position.x += penetration_x;
        m_velocity.x = 0;
        m_collided_left = true;
    }
    if (map->is_solid(right, &penetration_x, &penetration_y) && m_velocity.x > 0)
    {
        m_position.x -= penetration_x;
        m_velocity.x = 0;
        m_collided_right = true;
    }
}



void Entity::render(ShaderProgram* program){
    
    if (!m_is_active) return;
    
    program->set_model_matrix(m_model_matrix);

    if (m_animation_indices != NULL)
    {
        draw_sprite_from_texture_atlas(program, m_texture_id, m_animation_indices[m_animation_index]);
        return;
    }

    float vertices[] = { -0.5, -0.5, 0.5, -0.5, 0.5, 0.5, -0.5, -0.5, 0.5, 0.5, -0.5, 0.5 };
    float tex_coords[] = { 0.0,  1.0, 1.0,  1.0, 1.0, 0.0,  0.0,  1.0, 1.0, 0.0,  0.0, 0.0 };

    glBindTexture(GL_TEXTURE_2D, m_texture_id);

    glVertexAttribPointer(program->get_position_attribute(), 2, GL_FLOAT, false, 0, vertices);
    glEnableVertexAttribArray(program->get_position_attribute());
    glVertexAttribPointer(program->get_tex_coordinate_attribute(), 2, GL_FLOAT, false, 0, tex_coords);
    glEnableVertexAttribArray(program->get_tex_coordinate_attribute());

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(program->get_position_attribute());
    glDisableVertexAttribArray(program->get_tex_coordinate_attribute());
}


bool const Entity::check_collision(Entity* other) const
{
    if (other == this) return false;
    // If either entity is inactive, there shouldn't be any collision
    if (!m_is_active || !other->m_is_active) return false;

    float x_distance = fabs(m_position.x - other->m_position.x) - ((m_width + other->m_width) / 2.0f);
    float y_distance = fabs(m_position.y - other->m_position.y) - ((m_height + other->m_height) / 2.0f);

    return x_distance < 0.0f && y_distance < 0.0f;
}
