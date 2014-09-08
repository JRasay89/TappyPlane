#ifndef TAPPYPLANE_H_
#define TAPPYPLANE_H_

#include "../Core/Game.h"

//Entities
#include "../Entity/Background.h"
#include "../Entity/Plane.h"
#include "../Entity/Ground.h"
#include "../Entity/RockManager.h"

//The states
#include "../State/StateManager.h"
#include "../State/ReadyState.h"
#include "../State/RunState.h"
#include "../State/GameOverState.h"

#include "../UI/PlayerScore.h"

class TappyPlane : public Game
{
private:
    StateManager stateManager_;
    ReadyState readyState_;
    RunState runState_;
    GameOverState gameOverState_;

    Background background_;
    Plane plane_;
    Ground ground_;
    RockManager rockManager_;

    PlayerScore score_;
public:
    bool init();
    void update(int deltaTime);
    void draw();
    void free();

    Background* getBackground();
    Plane* getPlane();
    Ground* getGround();
    RockManager* getRockManager();
    PlayerScore* getPlayerScore();
};
#endif // TAPPYPLANE_H_

