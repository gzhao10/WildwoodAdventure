#include "LevelB.h"
#include "Utility.h"

#define LEVEL_WIDTH 29
#define LEVEL_HEIGHT 25

unsigned int LEVELB_DATA[] =
{
    //                  5                   10                  15                  20                  25
    81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
    81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
    81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
    81, 81, 81, 81, 81, 81, 81, 97, 98, 99, 97, 98, 81, 81, 81, 81, 97, 98, 99, 97, 81, 81, 81, 81, 81, 81, 81, 81, 81,
    81, 81, 81, 81, 81, 81,100,  0,  1,  1,  1,  2, 96, 98, 99,100,  0,  1,  1,  2, 96, 97, 98, 81, 81, 81, 81, 81, 81,
    81, 81, 81, 81, 81,100,  0, 20, 39, 20, 39,  8,  1,  1,  1,  1, 20, 23, 23, 20,  1,  1,  2, 80, 81, 81, 81, 81, 81,
    81, 81, 81, 81, 82,  0,  8, 42, 26, 26, 10, 74, 20, 20, 20, 20,  8, 31, 13, 20, 54, 55, 18, 80, 81, 81, 81, 81, 81,
    81, 81, 81, 81, 82, 16,  6, 58, 31, 45, 45, 45, 45, 45,  7,  8,  7, 20, 44, 57, 56, 54, 18, 80, 81, 81, 81, 81, 81,
    81, 81, 81, 81, 82, 16, 22,  6, 26, 26, 26, 25,104, 20, 20,  7, 20, 20, 28, 13, 20, 20, 18, 80, 81, 81, 81, 81, 81,
    81, 81, 81, 81, 82, 16, 38, 22, 23,  8, 20,  7, 20, 20, 20, 20, 20,  7, 20, 20, 20, 20, 18, 80, 81, 81, 81, 81, 81,
    81, 81, 81, 81, 82, 16,  7, 38,  8,  7, 20, 35, 65, 65, 65, 65, 65, 36, 20, 35, 65, 36, 18, 80, 81, 81, 81, 81, 81,
    81, 81, 81, 81, 82, 16, 35, 65, 65, 65, 65, 66,100,  0,  1,  1,  1,  7,  8, 20,  1, 20, 18, 96, 81, 81, 81, 81, 81,
    81, 81, 81, 81, 81, 64, 66, 81,100,  0,  1,  1,  1, 20, 20, 20,  8,  7,  7, 20, 20, 20, 20,  2, 80, 81, 81, 81, 81,
    81, 81, 81, 81, 81, 81, 81,100,  0, 23, 20,  8, 12, 45, 45, 20,  7, 20, 20, 20,  0, 24,  2, 18, 80, 81, 81, 81, 81,
    81, 81, 81, 81, 81, 81, 82,  0, 20, 20, 20, 12, 29,  6, 20, 20, 20, 20, 20,  0, 24, 40, 18, 18, 80, 81, 81, 81, 81,
    81, 81, 81, 81, 81, 81,100, 16, 20, 20,  7, 44,  0, 22, 23,  2, 20,  7,  7, 16, 40, 22, 54, 18, 80, 81, 81, 81, 81,
    81, 81, 81, 81, 81, 82,  0, 20, 20,  8,  7,  7, 16, 38, 35, 50, 20,  8,  7, 16, 22, 38, 18, 18, 80, 81, 81, 81, 81,
    81, 81, 81, 81, 81, 84, 16,  8,  7, 20, 44,  8, 48, 36, 56, 20, 20, 20,  8, 48, 38, 20, 18, 18, 80, 81, 81, 81, 81,
    81, 81, 81, 81,102, 90, 16, 20, 31, 45, 29, 20,  7, 48, 50,  7, 20, 20, 20, 20, 48, 49, 50, 18, 80, 81, 81, 81, 81,
    81, 81, 81, 81, 81, 82, 16, 20,  8,  7, 20, 20, 20, 20, 20, 20, 20,  8, 20, 20, 20, 20, 20, 18, 80, 81, 81, 81, 81,
    81, 81, 81, 81, 81, 82, 64, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 66, 80, 81, 81, 81, 81,
    81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
    81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
    81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
    81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81
};

LevelB::~LevelB()
{
    delete [] m_state.enemies;
    delete    m_state.player;
    delete [] m_state.items;
    delete    m_state.map;
    Mix_FreeMusic(m_state.bgm);
    Mix_FreeChunk(m_state.revive_sfx);
    Mix_FreeChunk(m_state.attack_sfx);
}

void LevelB::initialise(int lives){
    
    m_state.next_scene_id = -1;
    
    
    GLuint map_texture_id = Utility::load_texture("assets/tilemap.png");
    m_state.map = new Map(LEVEL_WIDTH, LEVEL_HEIGHT, LEVELB_DATA, map_texture_id, 1.0f, 16, 16);

    // ––––– PLAYER ––––– //
    GLuint player_texture_id = Utility::load_texture("assets/player.png");
    
    m_state.player = new Entity();
    m_state.player->set_entity_type(PLAYER);
    m_state.player->m_num_lives = lives;
    m_state.player->set_position(glm::vec3(7.0f, -18.0f, 0.0f));
    m_state.player->set_movement(glm::vec3(0.0f));
    m_state.player->set_speed(2.75f);
    m_state.player->m_texture_id = player_texture_id;
    m_state.player->m_enemies_killed = 0;
    m_state.player->m_has_sword = true;

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
    
    for (int i = 0; i < 7; i++){
        m_state.enemies[i].set_entity_type(ENEMY);
        m_state.enemies[i].set_ai_type(WALKER);
        m_state.enemies[i].m_texture_id = slime_texture_id;
        m_state.enemies[i].set_height(0.5f);
        m_state.enemies[i].set_width(0.5f);
        m_state.enemies[i].set_speed(0.75f);
        m_state.enemies[i].m_num_lives = 2;
        
        m_state.enemies[i].m_walking[m_state.enemies[i].RIGHT]   = new int[6] { 7, 8, 9, 10, 11, 12 };
        m_state.enemies[i].m_walking[m_state.enemies[i].LEFT]   = new int[6] { 19, 18, 17, 16, 15, 14 };
        m_state.enemies[i].m_animation_frames  = 6;
        m_state.enemies[i].m_animation_index   = 0;
        m_state.enemies[i].m_animation_time    = 0.0f;
        m_state.enemies[i].m_animation_cols    = 7;
        m_state.enemies[i].m_animation_rows    = 5;
        m_state.enemies[i].m_death = new int[5] {28, 29, 30, 31, 32};
        m_state.enemies[i].m_death_frames = 5;
        
    }
    
    m_state.enemies[0].set_ai_state(ROAM_RIGHT);
    m_state.enemies[0].m_animation_indices = m_state.enemies[0].m_walking[m_state.enemies[0].RIGHT];
    m_state.enemies[0].set_position(glm::vec3(14.0f, -12.0f, 0.0f));
    m_state.enemies[0].set_left_edge(14.0f);
    m_state.enemies[0].set_right_edge(17.0f);
    
    m_state.enemies[1].set_ai_state(ROAM_RIGHT);
    m_state.enemies[1].m_animation_indices = m_state.enemies[1].m_walking[m_state.enemies[1].RIGHT];
    m_state.enemies[1].set_position(glm::vec3(13.0f, -6.0f, 0.0f));
    m_state.enemies[1].set_left_edge(13.0f);
    m_state.enemies[1].set_right_edge(15.0f);
    
    m_state.enemies[2].set_ai_state(ROAM_LEFT);
    m_state.enemies[2].m_animation_indices = m_state.enemies[2].m_walking[m_state.enemies[2].LEFT];
    m_state.enemies[2].set_position(glm::vec3(11.0f, -15.0f, 0.0f));
    m_state.enemies[2].set_left_edge(8.0f);
    m_state.enemies[2].set_right_edge(10.0f);
    
    m_state.enemies[3].set_ai_state(ROAM_RIGHT);
    m_state.enemies[3].m_animation_indices = m_state.enemies[3].m_walking[m_state.enemies[3].RIGHT];
    m_state.enemies[3].set_position(glm::vec3(9.0f, -19.0f, 0.0f));
    m_state.enemies[3].set_left_edge(9.0f);
    m_state.enemies[3].set_right_edge(12.0f);
    
    m_state.enemies[4].set_ai_state(ROAM_LEFT);
    m_state.enemies[4].m_animation_indices = m_state.enemies[4].m_walking[m_state.enemies[4].LEFT];
    m_state.enemies[4].set_position(glm::vec3(19.0f, -9.0f, 0.0f));
    m_state.enemies[4].set_left_edge(17.0f);
    m_state.enemies[4].set_right_edge(19.0f);
    
    m_state.enemies[5].set_ai_state(ROAM_RIGHT);
    m_state.enemies[5].m_animation_indices = m_state.enemies[5].m_walking[m_state.enemies[5].RIGHT];
    m_state.enemies[5].set_position(glm::vec3(15.0f, -17.0f, 0.0f));
    m_state.enemies[5].set_left_edge(15.0f);
    m_state.enemies[5].set_right_edge(17.0f);
    
    m_state.enemies[6].set_ai_state(ROAM_LEFT);
    m_state.enemies[6].m_animation_indices = m_state.enemies[6].m_walking[m_state.enemies[6].LEFT];
    m_state.enemies[6].set_position(glm::vec3(22.0f, -19.0f, 0.0f));
    m_state.enemies[6].set_left_edge(18.0f);
    m_state.enemies[6].set_right_edge(22.0f);
    
    GLuint skeleton_texture_id = Utility::load_texture("assets/skeleton.png");
    
    for (int i = 7; i < 12; i++){
        m_state.enemies[i].set_entity_type(ENEMY);
        m_state.enemies[i].set_ai_type(GUARD);
        m_state.enemies[i].set_ai_state(IDLE);
        m_state.enemies[i].m_texture_id = skeleton_texture_id;
        m_state.enemies[i].set_movement(glm::vec3(0.0f));
        m_state.enemies[i].set_speed(0.5f);
        m_state.enemies[i].set_height(0.5f);
        m_state.enemies[i].set_width(0.5f);
        m_state.enemies[i].m_num_lives = 2;
        
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
    
    
    m_state.enemies[7].set_position(glm::vec3(9.0f, -17.0f, 0.0f));
    m_state.enemies[8].set_position(glm::vec3(17.0f, -17.0f, 0.0f));
    m_state.enemies[9].set_position(glm::vec3(15.0f, -13.0f, 0.0f));
    m_state.enemies[10].set_position(glm::vec3(17.0f, -7.0f, 0.0f));
    m_state.enemies[11].set_position(glm::vec3(20.0f, -11.0f, 0.0f));

    
    // ––––– POTION ––––– //
    GLuint potion_texture_id = Utility::load_texture("assets/potion.png");
    
    m_state.items = new Entity[ITEM_COUNT];
    
    m_state.items[0].set_entity_type(ITEM);
    m_state.items[0].m_texture_id = potion_texture_id;
    m_state.items[0].set_position(glm::vec3(8.0f, -6.85f, 0.0f));

    // ––––– AUDIO ––––– //
    m_state.revive_sfx = Mix_LoadWAV("assets/revive.wav");
    m_state.attack_sfx = Mix_LoadWAV("assets/attack.wav");
    
}


void LevelB::update(float delta_time){
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
    for (int i = 7; i < 12; i++){
        m_state.enemies[i].set_model_matrix(glm::scale(m_state.enemies[i].get_model_matrix(),
                                                    glm::vec3(1.5f, 1.5f, 0.0f)));
    }
    m_state.items[0].set_model_matrix(glm::scale(m_state.items[0].get_model_matrix(),
                                                glm::vec3(0.5f, 0.5f, 0.0f)));
    
    
    //Other conditions
    if (m_state.player->m_enemies_killed == 12) m_state.next_scene_id = 3;
    
    if (m_state.player->m_enemies_killed == 7){
        for (int i = 7; i < 12; i++){
            m_state.enemies[i].activate();
        }
    }
    
    if (!m_state.player->m_drank_potion && glm::distance(m_state.player->get_position(), m_state.items[0].get_position()) < 0.75f) {
        m_state.items[0].deactivate();
        if (m_state.player->m_num_lives < 3) m_state.player->m_num_lives++;
        m_state.player->m_drank_potion = true;
    }
    
    if (m_state.player->m_num_lives > 0 && m_state.player->m_revive){
        Mix_PlayChannel(-1, m_state.revive_sfx, 0);
        m_state.player->m_is_dead = false;
        m_state.player->m_revive = false;
        m_state.player->activate();
        m_state.player->set_position(glm::vec3(7.0f, -18.0f, 0.0f));
        m_state.player->set_movement(glm::vec3(0.0f));
        
        
        m_state.enemies[0].set_ai_state(ROAM_RIGHT);
        m_state.enemies[0].m_animation_indices = m_state.enemies[0].m_walking[m_state.enemies[0].RIGHT];
        m_state.enemies[0].set_position(glm::vec3(14.0f, -12.0f, 0.0f));
        
        m_state.enemies[1].set_ai_state(ROAM_RIGHT);
        m_state.enemies[1].m_animation_indices = m_state.enemies[1].m_walking[m_state.enemies[1].RIGHT];
        m_state.enemies[1].set_position(glm::vec3(13.0f, -6.0f, 0.0f));
        
        
        m_state.enemies[2].set_ai_state(ROAM_LEFT);
        m_state.enemies[2].m_animation_indices = m_state.enemies[2].m_walking[m_state.enemies[2].LEFT];
        m_state.enemies[2].set_position(glm::vec3(11.0f, -15.0f, 0.0f));
        
        
        m_state.enemies[3].set_ai_state(ROAM_RIGHT);
        m_state.enemies[3].m_animation_indices = m_state.enemies[3].m_walking[m_state.enemies[3].RIGHT];
        m_state.enemies[3].set_position(glm::vec3(9.0f, -19.0f, 0.0f));
        
        
        m_state.enemies[4].set_ai_state(ROAM_LEFT);
        m_state.enemies[4].m_animation_indices = m_state.enemies[4].m_walking[m_state.enemies[4].LEFT];
        m_state.enemies[4].set_position(glm::vec3(19.0f, -9.0f, 0.0f));
        
        m_state.enemies[5].set_ai_state(ROAM_RIGHT);
        m_state.enemies[5].m_animation_indices = m_state.enemies[5].m_walking[m_state.enemies[5].RIGHT];
        m_state.enemies[5].set_position(glm::vec3(15.0f, -17.0f, 0.0f));
        
        m_state.enemies[6].set_ai_state(ROAM_LEFT);
        m_state.enemies[6].m_animation_indices = m_state.enemies[6].m_walking[m_state.enemies[6].LEFT];
        m_state.enemies[6].set_position(glm::vec3(22.0f, -19.0f, 0.0f));
        
        m_state.enemies[7].set_position(glm::vec3(9.0f, -17.0f, 0.0f));
        m_state.enemies[8].set_position(glm::vec3(17.0f, -17.0f, 0.0f));
        m_state.enemies[9].set_position(glm::vec3(15.0f, -13.0f, 0.0f));
        m_state.enemies[10].set_position(glm::vec3(17.0f, -7.0f, 0.0f));
        m_state.enemies[11].set_position(glm::vec3(20.0f, -11.0f, 0.0f));
    }
}


void LevelB::render(ShaderProgram *program)
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
