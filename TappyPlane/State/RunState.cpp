#include "RunState.h"

void RunState::init(Graphics* graphics, Image* image, Input* input, OutlineFont* outlineFont, Background* background, Plane* plane, Ground* ground, RockManager* rockManager, PlayerScore* score)
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

    //Initialize the rocks type to be the same as the ground
    rockManager_->init(ground_->getType());

    //Initialize score
    score_ = score;
}

void RunState::update(int deltaTime)
{
    if (input_->isKeyHit(SDLK_ESCAPE)) {
        getManager()->popState();
    }

    rockManager_->update(deltaTime);
    ground_->update(deltaTime);
    plane_->update(input_, deltaTime);

    score_->updateScore(plane_->getOffsetX(), rockManager_->getRocks());
    score_->updateBestScore();


    //check for any collision with the plane and the ground
    if (collisionDetection_.detectCollision(plane_->getCollisionRect(), ground_->getCollisionRect()) ||
        collisionDetection_.detectCollision(plane_->getCollisionRect(), ground_->getCollisionRectLoop()))
    {
        printf("Ground Collision!\n");
        getManager()->popState();
    }

    //Check for any collision with the plane and the north and south rocks
    for (int i = 0; i < rockManager_->getRocks().size(); i++)
    {
        if (collisionDetection_.detectCollision(plane_->getCollisionRect(), rockManager_->getRocks()[i].getNorthCollisionRects()) ||
            collisionDetection_.detectCollision(plane_->getCollisionRect(), rockManager_->getRocks()[i].getSouthCollisionRects()))
        {
            getManager()->popState();
        }

    }


}

void RunState::draw()
{
    //Draw the Background
    background_->draw(graphics_, image_);
    //Draw the rocks
    rockManager_->draw(graphics_, image_);
    //Draw the ground
    ground_->draw(graphics_,image_);
    //Draw the plane
    plane_->draw(graphics_,image_);
    //Draw the score
    score_->drawScore(graphics_, outlineFont_);


    /*****************************************
     Draw the collision boxes for debugging
    ******************************************/
    //collisionDetection_.drawCollisionBox(graphics_, plane_->getCollisionRect());
    //collisionDetection_.drawCollisionBox(graphics_, ground_->getCollisionRect());
    //collisionDetection_.drawCollisionBox(graphics_, ground_->getCollisionRectLoop());

    /*
    for (int i = 0; i < rockManager_->getRocks().size(); i++)
    {
        collisionDetection_.drawCollisionBox(graphics_, rockManager_->getRocks()[i].getNorthCollisionRects());
        collisionDetection_.drawCollisionBox(graphics_, rockManager_->getRocks()[i].getSouthCollisionRects());

    }
    */

}

