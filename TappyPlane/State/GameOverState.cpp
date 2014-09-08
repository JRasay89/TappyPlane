#include "GameOverState.h"

void GameOverState::init(Graphics* graphics, Image* image, Input* input,OutlineFont* outlineFont, Background* background, Plane* plane, Ground* ground, RockManager* rockManager, PlayerScore* score)
{
    //Initialize the core objects
    graphics_ = graphics;
    image_ = image;
    input_ = input;
    outlineFont_ = outlineFont;

    //Initialize the entities
    background_ = background;
    plane_ = plane;
    ground_ = ground;
    rockManager_ = rockManager;
    score_ = score;
}

void GameOverState::update(int deltaTime)
{
    if (input_->isKeyHit(SDLK_ESCAPE))
    {
        getManager()->clearAll();
    }

    plane_->update(deltaTime, true);
}

void GameOverState::draw()
{

    //Draw the background
    background_->draw(graphics_, image_);

    //Draw the rocks
    rockManager_->draw(graphics_, image_);

    //Draw the ground
    ground_->draw(graphics_,image_);

    //Draw the plane
    plane_->draw(graphics_,image_);

    //Draw the final score
    score_->drawFinalScore(graphics_, image_, outlineFont_);

    //Draw the text
    outlineFont_->drawOutlineText("Press Esc To Quit",260,400,0,0,0,graphics_);
}

