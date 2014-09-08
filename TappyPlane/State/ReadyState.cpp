#include "ReadyState.h"

void ReadyState::init(Graphics* graphics, Image* image, Input* input, OutlineFont* outlineFont, Background* background, Plane* plane, Ground* ground)
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


}

/*
 * Update the entities
 * @param deltaTime is the change in time since last update
 */
void ReadyState::update(int deltaTime)
{
    //printf("ReadyState Update\n");
    if (input_->isKeyHit(SDLK_ESCAPE)) {
        getManager()->clearAll();
    }
    if (input_->isKeyHit(SDLK_SPACE)) {
        getManager()->popState();
    }

    plane_->update(deltaTime, false);
}
void ReadyState::draw()
{
    //Draw the Background
    background_->draw(graphics_, image_);

    //Get ready image
    image_->draw(200,20,0,913,400,73,graphics_);

    //Draw the text
    outlineFont_->drawOutlineText("Press Space To Play", 250, 300, 0, 0, 0, graphics_);
    outlineFont_->drawOutlineText("Press Esc To Quit", 250, 350, 0, 0, 0, graphics_);

    //Draw the ground
    ground_->draw(graphics_,image_);

    //Draw the plane
    plane_->draw(graphics_,image_);
}

