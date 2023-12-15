#include "LevelA.h"
#include "Utility.h"

#define LEVEL_WIDTH 30
#define LEVEL_HEIGHT 25

unsigned int LEVELA_DATA[] = {
//                  5                   10                  15                  20                  25
81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 81, 97, 98, 99, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 97, 98, 99, 81, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 82,  0,  1,  2, 96, 97, 97, 97, 81, 81, 97, 98, 99, 97, 98,100,  0,  1,  2, 80, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 82, 16, 20, 20,  1,  1,  1,  2, 96,100,  0,  1,  1,  1,  1,  1, 20, 20,  6, 80, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 82, 16, 28, 45, 45, 13,  8, 20,  1,  1, 20, 20, 20, 20, 20, 20,  7, 55, 22, 80, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 82, 16, 20,  7,  7, 62, 45, 45, 14, 20,  8, 20, 20, 20,  7, 20, 20, 20, 38, 80, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 82, 16, 20, 20,  7, 44,  8, 20, 20, 20, 20, 45, 13, 20, 20, 55, 20, 20, 18, 80, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 82, 48, 49, 49, 36,  8, 20,  6, 20, 24,  6, 20, 44, 20, 54, 55,  8, 20, 18, 80, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 82, 16, 20, 56, 16, 20, 20, 22,  6, 40, 22, 20, 20,  7, 20, 20, 20, 35, 66, 80, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 82, 64, 51, 52, 16,  7, 44, 38, 22, 22, 38, 20, 20,  7, 20,  8, 20, 18, 80, 81, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 81, 81, 81, 82, 16, 12, 29, 20, 38, 38, 20,  8, 20, 28, 13,  6, 20, 18, 96, 81, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 81, 81, 81,100, 16, 44,  8, 20, 20,  7, 20, 20, 39,  8, 44, 22,  6, 20,  2, 80, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 81, 81, 82,  0, 20, 44,  6,  6, 20, 20, 20, 39, 20, 20, 20, 40, 22, 20, 18, 83, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 81, 81,100, 16, 12, 29, 22, 22,  2, 20,  8, 20,  7,  8, 20, 38, 38, 20, 18, 91, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 81,100,  0, 20, 29,  0, 38, 38, 56, 20, 20, 20, 20, 20, 20, 20, 20,  7, 18, 96, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 82,  0, 20, 20, 20, 48, 36, 35, 50, 20, 35, 65, 65, 65, 36,  7,  8,  7, 20,  2, 80, 81, 81, 81, 81,
81, 81, 81, 81, 81, 82, 16, 20, 20,  8, 20, 48, 50, 20, 20, 18, 80, 81, 82, 16,  7, 23, 20, 20, 18, 80, 81, 81, 81, 81,
81, 81, 81, 81, 81,100, 16, 20,  7,  7, 20, 20,  8, 20, 35, 66, 81, 81,100, 16,  8, 20, 20,  7, 18, 80, 81, 81, 81, 81,
81, 81, 81, 81, 82,  0, 20, 20, 20, 20, 20, 20, 20, 35, 66, 81, 81, 82,  0, 20, 20,  8,  8, 20, 18, 80, 81, 81, 81, 81,
81, 81, 81, 81, 81, 64, 65, 65, 65, 65, 65, 65, 65, 66, 80, 81, 81, 81, 64, 65, 65, 65, 65, 65, 66, 80, 81, 81, 81, 81,
81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81
};

LevelA::~LevelA()
{
    delete [] m_state.enemies;
    delete    m_state.player;
    delete [] m_state.items;
    delete    m_state.map;
    Mix_FreeMusic(m_state.bgm);
    Mix_FreeChunk(m_state.revive_sfx);
    Mix_FreeChunk(m_state.attack_sfx);
}

void LevelA::initialise(int lives){
    
    m_state.next_scene_id = -1;
    
    
    GLuint map_texture_id = Utility::load_texture("assets/tilemap.png");
    m_state.map = new Map(LEVEL_WIDTH, LEVEL_HEIGHT, LEVELA_DATA, map_texture_id, 1.0f, 16, 16);

    // ––––– PLAYER ––––– //
    GLuint player_texture_id = Utility::load_texture("assets/player.png");
    
    m_state.player = new Entity();
    m_state.player->set_entity_type(PLAYER);
    m_state.player->m_num_lives = lives;
    m_state.player->set_position(glm::vec3(7.0f, -5.0f, 0.0f));
    m_state.player->set_movement(glm::vec3(0.0f));
    m_state.player->set_speed(2.75f);
    m_state.player->m_texture_id = player_texture_id;
    m_state.player->m_enemies_killed = 0;

    // Walking
    m_state.player->m_walking[m_state.player->LEFT]   = new int[4] { 12, 13, 15, 16 };
    m_state.player->m_walking[m_state.player->RIGHT]  = new int[4] { 26, 25, 29, 28 };
    m_state.player->m_walking[m_state.player->UP]     = new int[4] { 35, 34, 35, 31 };
    m_state.player->m_walking[m_state.player->DOWN]   = new int[4] { 20, 19, 23, 22 };
    
    m_state.player->m_attacking[m_state.player->LEFT]   = new int[4] { 6, 7, 8, 9 };
    m_state.player->m_attacking[m_state.player->RIGHT]  = new int[4] { 42, 43, 44, 45 };
    m_state.player->m_attacking[m_state.player->UP]     = new int[4] { 48, 49, 50, 51 };
    m_state.player->m_attacking[m_state.player->DOWN]   = new int[4] { 36, 37, 38, 39 };
    
    m_state.player->m_death = new int[4] {54, 55, 56, 57};
    m_state.player->m_death_frames = 4;

    m_state.player->m_animation_indices = m_state.player->m_walking[m_state.player->RIGHT];
    m_state.player->m_animation_frames  = 4;
    m_state.player->m_animation_index   = 0;
    m_state.player->m_animation_time    = 0.0f;
    m_state.player->m_animation_cols    = 6;
    m_state.player->m_animation_rows    = 10;
    m_state.player->set_height(0.75f);
    m_state.player->set_width(0.65f);

    
    // ––––– ENEMIES ––––– //
    GLuint slime_texture_id = Utility::load_texture("assets/slime.png");

    m_state.enemies = new Entity[ENEMY_COUNT];
    
    for (int i = 0; i < 8; i++){
        m_state.enemies[i].set_entity_type(ENEMY);
        m_state.enemies[i].set_ai_type(WALKER);
        m_state.enemies[i].m_texture_id = slime_texture_id;
        m_state.enemies[i].set_height(0.5f);
        m_state.enemies[i].set_width(0.5f);
        
        m_state.enemies[i].m_animation_index   = 0;
        m_state.enemies[i].m_animation_time    = 0.0f;
        m_state.enemies[i].m_animation_cols    = 7;
        m_state.enemies[i].m_animation_rows    = 5;
        m_state.enemies[i].m_death = new int[5] {28, 29, 30, 31, 32};
        m_state.enemies[i].m_death_frames = 5;
    }
    
    for (int i = 0; i < 4; i++){
        m_state.enemies[i].set_ai_state(ROAM_RIGHT);
        m_state.enemies[i].m_walking[m_state.enemies[i].RIGHT]   = new int[6] { 7, 8, 9, 10, 11, 12 };
        m_state.enemies[i].m_walking[m_state.enemies[i].LEFT]   = new int[6] { 19, 18, 17, 16, 15, 14 };
        m_state.enemies[i].m_animation_indices = m_state.enemies[i].m_walking[m_state.enemies[i].RIGHT];
        m_state.enemies[i].m_animation_frames  = 6;
        
        
        m_state.enemies[i].set_speed(0.75f);
    }
    
    for (int i = 4; i < 8; i++){
        m_state.enemies[i].set_ai_state(ROAM_LEFT);
        m_state.enemies[i].m_walking[m_state.enemies[i].RIGHT]   = new int[4] { 0, 1, 2, 3 };
        m_state.enemies[i].m_walking[m_state.enemies[i].LEFT]   = new int[4] { 24, 23, 22, 21 };
        m_state.enemies[i].m_animation_indices = m_state.enemies[i].m_walking[m_state.enemies[i].LEFT];
        m_state.enemies[i].m_animation_frames  = 4;
        
        m_state.enemies[i].set_speed(0.5f);
    }
    
    m_state.enemies[0].set_position(glm::vec3(16.0f, -6.0f, 0.0f));
    m_state.enemies[0].set_left_edge(16.0f);
    m_state.enemies[0].set_right_edge(20.0f);
    
    m_state.enemies[1].set_position(glm::vec3(7.0f, -8.0f, 0.0f));
    m_state.enemies[1].set_left_edge(7.0f);
    m_state.enemies[1].set_right_edge(10.0f);
    
    m_state.enemies[2].set_position(glm::vec3(16.0f, -16.0f, 0.0f));
    m_state.enemies[2].set_left_edge(16.0f);
    m_state.enemies[2].set_right_edge(18.0f);
    
    m_state.enemies[3].set_position(glm::vec3(8.0f, -19.0f, 0.0f));
    m_state.enemies[3].set_left_edge(8.0f);
    m_state.enemies[3].set_right_edge(11.0f);
    
    m_state.enemies[4].set_position(glm::vec3(21.0f, -11.0f, 0.0f));
    m_state.enemies[4].set_left_edge(18.0f);
    m_state.enemies[4].set_right_edge(21.0f);
    
    m_state.enemies[5].set_position(glm::vec3(16.0f, -8.0f, 0.0f));
    m_state.enemies[5].set_left_edge(14.0f);
    m_state.enemies[5].set_right_edge(16.0f);
    
    m_state.enemies[6].set_position(glm::vec3(23.0f, -20.0f, 0.0f));
    m_state.enemies[6].set_left_edge(20.0f);
    m_state.enemies[6].set_right_edge(23.0f);
    
    m_state.enemies[7].set_position(glm::vec3(15.0f, -13.0f, 0.0f));
    m_state.enemies[7].set_left_edge(12.0f);
    m_state.enemies[7].set_right_edge(15.0f);
    
    
    GLuint skeleton_texture_id = Utility::load_texture("assets/skeleton.png");
    
    for (int i = 8; i < 13; i++){
        m_state.enemies[i].set_entity_type(ENEMY);
        m_state.enemies[i].set_ai_type(GUARD);
        m_state.enemies[i].set_ai_state(IDLE);
        m_state.enemies[i].m_texture_id = skeleton_texture_id;
        m_state.enemies[i].set_movement(glm::vec3(0.0f));
        m_state.enemies[i].set_speed(0.5f);
        m_state.enemies[i].set_height(0.5f);
        m_state.enemies[i].set_width(0.5f);
        
        m_state.enemies[i].m_walking[m_state.enemies[i].LEFT]   = new int[4] { 7, 6, 5, 4};
        m_state.enemies[i].m_walking[m_state.enemies[i].RIGHT]  = new int[4] { 16, 17, 18, 19 };
        m_state.enemies[i].m_walking[m_state.enemies[i].UP]   = new int[4] { 21, 20, 23, 22};
        m_state.enemies[i].m_walking[m_state.enemies[i].DOWN]  = new int[4] { 13, 12, 15, 14 };
        m_state.enemies[i].m_animation_indices = m_state.enemies[i].m_walking[m_state.enemies[i].RIGHT];
        m_state.enemies[i].m_animation_frames  = 4;
        m_state.enemies[i].m_animation_index   = 0;
        m_state.enemies[i].m_animation_time    = 0.0f;
        m_state.enemies[i].m_animation_cols    = 4;
        m_state.enemies[i].m_animation_rows    = 12;
        m_state.enemies[i].m_death = new int[4] {40, 41, 42, 43};
        m_state.enemies[i].m_death_frames  = 4;
        m_state.enemies[i].deactivate();
    }
    
    
    m_state.enemies[8].set_position(glm::vec3(17.0f, -8.0f, 0.0f));
    m_state.enemies[9].set_position(glm::vec3(21.0f, -19.0f, 0.0f));
    m_state.enemies[10].set_position(glm::vec3(8.0f, -18.0f, 0.0f));
    m_state.enemies[11].set_position(glm::vec3(10.0f, -6.0f, 0.0f));
    m_state.enemies[12].set_position(glm::vec3(10.0f, -11.0f, 0.0f));


    // ––––– SWORD ––––– //
    GLuint sword_texture_id = Utility::load_texture("assets/sword.png");
    GLuint ship_texture_id = Utility::load_texture("assets/ship.png");
    
    m_state.items = new Entity[ITEM_COUNT];
    
    m_state.items[0].set_entity_type(ITEM);
    m_state.items[0].m_texture_id = sword_texture_id;
    m_state.items[0].set_position(glm::vec3(8.0f, -18.0f, 0.0f));
    
    m_state.items[1].set_entity_type(ITEM);
    m_state.items[1].m_texture_id = ship_texture_id;
    m_state.items[1].set_position(glm::vec3(25.0f, -14.75f, 0.0f));
    m_state.items[1].deactivate();

    // ––––– AUDIO ––––– //
    m_state.revive_sfx = Mix_LoadWAV("assets/revive.wav");
    m_state.attack_sfx = Mix_LoadWAV("assets/attack.wav");
}


void LevelA::update(float delta_time){
    //Updates
    m_state.player->update(delta_time, m_state.player, m_state.enemies, ENEMY_COUNT, m_state.map);
    
    
    for (int i = 0; i < ENEMY_COUNT; i++){
        m_state.enemies[i].update(delta_time, m_state.player, 0, 0, m_state.map);
    }
    
    for (int i = 0; i < ITEM_COUNT; i++){
        m_state.items[i].update(delta_time, m_state.player, 0, 0, m_state.map);
    }
    
    // Update model matrices
    m_state.player->set_model_matrix(glm::scale(m_state.player->get_model_matrix(),
                                                glm::vec3(1.75f, 1.75f, 0.0f)));
    m_state.items[0].set_model_matrix(glm::scale(m_state.items[0].get_model_matrix(),
                                                glm::vec3(0.5f, 0.5f, 0.0f)));
    for (int i = 8; i < 13; i++){
        m_state.enemies[i].set_model_matrix(glm::scale(m_state.enemies[i].get_model_matrix(),
                                                    glm::vec3(1.5f, 1.5f, 0.0f)));
    }
    
    //Other conditions
    if (m_state.player->m_enemies_killed == 13 && m_state.player->get_position().x > 24.0f && m_state.player->get_position().y > -16.0f) m_state.next_scene_id = 2;
    
    if (m_state.player->m_enemies_killed == 8){
        for (int i = 8; i < 13; i++){
            m_state.enemies[i].activate();
        }
    }
    
    if (m_state.player->m_enemies_killed == 13){
        m_state.items[1].activate();
    }
    
    if (!m_state.player->m_has_sword &&glm::distance(m_state.player->get_position(), m_state.items[0].get_position()) < 0.75f) {
        m_state.items[0].deactivate();
        m_state.player->m_has_sword = true;
    }
    
    if (m_state.player->m_num_lives > 0 && m_state.player->m_revive){
        Mix_PlayChannel(-1, m_state.revive_sfx, 0);
        m_state.player->m_is_dead = false;
        m_state.player->m_revive = false;
        m_state.player->activate();
        m_state.player->set_position(glm::vec3(7.0f, -5.0f, 0.0f));
        m_state.player->set_movement(glm::vec3(0.0f));
            
            

            
        for (int i = 8; i < 13; i++){
            m_state.enemies[i].set_ai_state(IDLE);
        }
        m_state.enemies[8].set_position(glm::vec3(20.0f, -6.0f, 0.0f));
        m_state.enemies[9].set_position(glm::vec3(21.0f, -19.0f, 0.0f));
        m_state.enemies[10].set_position(glm::vec3(8.0f, -18.0f, 0.0f));
        m_state.enemies[11].set_position(glm::vec3(10.0f, -6.0f, 0.0f));
        m_state.enemies[12].set_position(glm::vec3(10.0f, -11.0f, 0.0f));
    }
}


void LevelA::render(ShaderProgram *program)
{
    m_state.map->render(program);
    m_state.player->render(program);
    for (int i = 0; i < ENEMY_COUNT; i++){
        m_state.enemies[i].render(program);
    }
    for (int i = 0; i < ITEM_COUNT; i++){
        m_state.items[i].render(program);
    }
}
