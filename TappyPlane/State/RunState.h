#ifndef RUNSTATE_H_
#define RUNSTATE_H_

//Core
#include "../Core/Graphics.h"
#include "../Core/Image.h"
#include "../Core/Input.h"
#include "../Core/OutlineFont.h"

//State
#include "GameState.h"

//Entity
#include "../Entity/Background.h"
#include "../Entity/Plane.h"
#include "../Entity/Ground.h"
#include "../Entity/RockManager.h"
#include "../Entity/CollisionDetection.h"

#include "../UI/PlayerScore.h"


class RunState : public GameState
{
private:
    Graphics* graphics_;
    Image* image_;
    Input* input_;
    OutlineFont* outlineFont_;

    Background* background_;
    Plane* plane_;
    Ground* ground_;
    RockManager* rockManager_;

    PlayerScore* score_;

    CollisionDetection collisionDetection_;
public:
    void init(Graphics* graphics, Image* image, Input* input, OutlineFont* outlineFont, Background* background, Plane* plane, Ground* ground, RockManager* rockManger, PlayerScore* score);
    void update(int deltaTime);
    void draw();
};
#endif // RUNSTATE_H_

