#include "Ground.h"

namespace {
    //The width and height of the ground
    const int GROUND_WIDTH = 808;
    const int GROUND_HEIGHT = 71;

    //The grounds X axis velocity
    const float GROUND_VELOCITY_Y = 0.0f;
    const float GROUND_VELOCITY_X = 225.0f;

    //The ground's constant y axis position
    const float INITIAL_OFFSET_X = 0.0f;
    const float INITIAL_OFFSET_Y = 409.0f;


    //The X and Y position of the ground art in the sprite sheet
    const int SOURCE_SPRITE_OFFSET_X[4] = {0, 0, 0, 0};
    const int SOURCE_SPRITE_OFFSET_Y[4] = {0, 142, 71, 213};

    //The width, height, x and y values for the collision boxes
    const float COLLISION_BOX_W[34] = {36.0f, 55.0f, 25.0f, 25.0f, 15.0f, 105.0f,
                                    12.0f, 12.0f, 12.0f, 12.0f, 50.0f, 10.0f,
                                    10.0f, 65.0f, 5.0f, 7.0f, 7.0f, 7.0f,
                                    5.0f, 45.0f, 10.0f, 10.0f, 40.0f, 7.0f,
                                    7.0f, 7.0f, 45.0f, 7.0f, 7.0f, 92.0f,
                                    7.0f, 7.0f, 33.0f, 15.0f};

    const float COLLISION_BOX_H[34] = {35.0f, 25.0f, 28.0f, 33.0f, 45.0f, 15.0f,
                                    15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f,
                                    15.0f, 15.0f, 20.0f, 20.0f, 20.0f, 20.0f,
                                    20.0f, 20.0f, 20.0f, 15.0f, 15.0f, 22.0f,
                                    22.0f, 25.0f, 28.0f, 25.0f, 25.0f, 25.0f,
                                    25.0f, 25.0f, 25.0f, 25.0f};

    const float COLLISION_BOX_X[34] = {0.0f, 36.0f, 91.0f, 116.0f, 141.0f, 150.0f,
                                    255.0f, 267.0f, 279.0f, 291.0f, 303.0f, 353.0f,
                                    363.0f, 373.0f, 438.0f, 443.0f, 450.0f, 457.0f,
                                    464.0f, 469.0f, 514.0f, 524.0f, 534.0f, 574.0f,
                                    581.0f, 588.0f, 595.0f, 640.0f, 647.0f, 654.0f,
                                    746.0f, 753.0f, 760.0f, 793.0f};

    const float COLLISION_BOX_Y[34] = {35.0f, 45.0f, 42.0f, 37.0f, 25.0f, 10.0f,
                                    10.0f, 15.0f, 20.0f, 25.0f, 27.0f, 23.0f,
                                    17.0f, 13.0f, 15.0f, 22.0f, 28.0f, 35.0f,
                                    40.0f, 45.0f, 50.0f, 55.0f, 55.0f, 50.0f,
                                    45.0f, 37.0f, 26.0f, 18.0f, 10.0f, 2.0f,
                                    8.0f, 15.0f, 30.0f, 35.0f};
}

/*
 * The ground class constructor
 */
Ground::Ground() : collisionBoxes_(34), collisionBoxes_Loop_(34)
{
    //Randomly initialize the type of the ground
    srand(time(0));
    type_ = (Type)(rand() % 4);

    //Set the initial location of the ground
    setOffsetX(INITIAL_OFFSET_X);
    setOffsetY(INITIAL_OFFSET_Y);

    //Initialize the ground's velocity
    setVelocityX(GROUND_VELOCITY_X);
    setVelocityY(GROUND_VELOCITY_Y);

    //Initialize the width and height of the collision boxes
    for (int i = 0; i < collisionBoxes_.size(); i++)
    {

        collisionBoxes_[i].w = COLLISION_BOX_W[i];
        collisionBoxes_[i].h = COLLISION_BOX_H[i];
    }


    for (int i = 0; i < collisionBoxes_Loop_.size(); i++)
    {

        collisionBoxes_Loop_[i].w = COLLISION_BOX_W[i];
        collisionBoxes_Loop_[i].h = COLLISION_BOX_H[i];
    }

}

void Ground::update(int deltaTime)
{

    setOffsetX(getOffsetX() - (getVelocityX() * (deltaTime/1000.0f)));
    //cout << "Ground Offset X: " << getOffsetX() << endl;
    if (getOffsetX() <= -808.0f)
    {
        setOffsetX(0.0f);
    }

    //Shift the collision boxes
    shiftCollisionBoxes();

}
void Ground::draw(Graphics* graphics, Image* image)
{

    image->draw(getOffsetX(), getOffsetY(), SOURCE_SPRITE_OFFSET_X[type_], SOURCE_SPRITE_OFFSET_Y[type_], getSourceWidth(), getSourceHeight(), graphics);
    image->draw((getOffsetX() + GROUND_WIDTH), getOffsetY(), SOURCE_SPRITE_OFFSET_X[type_], SOURCE_SPRITE_OFFSET_Y[type_], getSourceWidth(), getSourceHeight(), graphics);
}

/*
 * Shift the collision boxes as the ground's location change
 */
void Ground::shiftCollisionBoxes()
{
    for (int i = 0; i < collisionBoxes_.size(); i++)
    {

        collisionBoxes_[i].x = getOffsetX() + COLLISION_BOX_X[i];
        collisionBoxes_[i].y = getOffsetY() + COLLISION_BOX_Y[i];
    }

    for (int i = 0; i < collisionBoxes_Loop_.size(); i++)
    {

        collisionBoxes_Loop_[i].x = getOffsetX() + COLLISION_BOX_X[i] + 808.0f;
        collisionBoxes_Loop_[i].y = getOffsetY() + COLLISION_BOX_Y[i];
    }
}

std::vector<SDL_Rect>& Ground::getCollisionRect()
{
    return collisionBoxes_;
}

std::vector<SDL_Rect>& Ground::getCollisionRectLoop()
{
    return collisionBoxes_Loop_;
}

int Ground::getType()
{
    return type_;
}
