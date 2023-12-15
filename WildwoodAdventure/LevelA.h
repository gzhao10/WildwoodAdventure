#include "Scene.h"

class LevelA : public Scene {
public:
    // ————— STATIC ATTRIBUTES ————— //
    int ENEMY_COUNT = 13;
    int ITEM_COUNT = 2;
    
    // ————— CONSTRUCTOR ————— //
    ~LevelA();
    
    // ————— METHODS ————— //
    void initialise(int lives) override;
    void update(float delta_time) override;
    void render(ShaderProgram *program) override;
};
