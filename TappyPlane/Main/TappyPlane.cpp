#include "TappyPlane.h"

namespace
{
    const int SCREENWIDTH = 800;
    const int SCREENHEIGHT = 480;
    const string GAMETITLE = "Tappy Plane";
    const bool ISFULLSCREEN = false;

}

bool TappyPlane::init()
{
    if (!initSystem(GAMETITLE, SCREENWIDTH, SCREENHEIGHT, ISFULLSCREEN))
    {
        return false;
    }

    gameOverState_.init(getGraphics(),getImage(), getInput(), getOutlineFont(), getBackground(), getPlane(), getGround(), getRockManager(), getPlayerScore());
    runState_.init(getGraphics(),getImage(), getInput(), getOutlineFont(), getBackground(), getPlane(), getGround(), getRockManager(), getPlayerScore());
    readyState_.init(getGraphics(),getImage(), getInput(), getOutlineFont(), getBackground(), getPlane(), getGround());

    stateManager_.addState(&gameOverState_);
    stateManager_.addState(&runState_);
    stateManager_.addState(&readyState_);
    return true;

}

void TappyPlane::update(int deltaTime)
{
    if (stateManager_.isEmpty()) {
        quitGame();
        return;
    }

    stateManager_.update(deltaTime);

}

void TappyPlane::draw()
{

    stateManager_.draw();

}

void TappyPlane::free()
{

}

/*
 * Returns the background object which is used to the draw the background
 * @return the background
 */
Background* TappyPlane::getBackground()
{
    return &background_;
}

Plane* TappyPlane::getPlane()
{
    return &plane_;
}

Ground* TappyPlane::getGround()
{
    return &ground_;
}

RockManager* TappyPlane::getRockManager()
{
    return &rockManager_;
}

PlayerScore* TappyPlane::getPlayerScore()
{
    return &score_;
}
