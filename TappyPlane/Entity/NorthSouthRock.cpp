#include "NorthSouthRock.h"

namespace
{
    //The width and height of the ground
    const int ROCK_WIDTH = 108;
    const int ROCK_HEIGHT = 239;

    //The grounds X axis velocity
    const float ROCK_VELOCITY_Y = 0.0f;
    const float ROCK_VELOCITY_X = 225.0f;

    //The maximum X and Y of the screen
    const int MAX_SCREEN_X = 800;
    const int MAX_SCREEN_Y = 480;

    //The maximum distance between the Top and Bottom Rocks
    const float MAX_DISTANCE_BETWEEN_ROCKS = 155.0f;

    const int INITIAL_OFFSET_X = 801; //Pixels  The Starting point of the rocks

    //The width, height, x and y values of the top rock's collision boxes
    const int COLLISION_BOX_NORTH_W[6] = {100,85,65,55,41,15};
    const int COLLISION_BOX_NORTH_H[6] = {42,40,30,25,50,50};

    const int COLLISION_BOX_NORTH_X[6] = {5,15,25,35,42,58};
    const int COLLISION_BOX_NORTH_Y[6] = {0,43,85,115,140,190};

    //The width, height, x and y values of the bottom rock's collision boxes
    const int COLLISION_BOX_SOUTH_W[6] = {15,41,55,65,85,100};
    const int COLLISION_BOX_SOUTH_H[6] = {50,50,25,30,40,42};

    const int COLLISION_BOX_SOUTH_X[6] = {58,42,35,25,15,5};
    const int COLLISION_BOX_SOUTH_Y[6] = {0,50,100,125,155,198};


}

NorthSouthRock::NorthSouthRock() : north_CollisionBoxes_(6), south_CollisionBoxes_(6)
{
    //Initialize the width and height of the north and south rocks
    northRock_.setSourceWidth(ROCK_WIDTH);
    northRock_.setSourceHeight(ROCK_HEIGHT);

    southRock_.setSourceWidth(ROCK_WIDTH);
    southRock_.setSourceHeight(ROCK_HEIGHT);

    //Set the initial x offset of the top and bottom rocks
    northRock_.setOffsetX(INITIAL_OFFSET_X);
    southRock_.setOffsetX(INITIAL_OFFSET_X);

    //Set a random value for the y offset of the north rock
    float randomOffsetY = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/240.0f));
    northRock_.setOffsetY( (randomOffsetY - ROCK_HEIGHT));

    //Determine the value of the south rock based on the value of the north rock, and the max distance

    //If the north rock is pass the screen
    //Set the y offset of the south rock to its maximum distance
    if (northRock_.getOffsetY() <= -153.0f)
    {
        southRock_.setOffsetY(241.0f);
    }
    else
    {
        southRock_.setOffsetY( northRock_.getOffsetY() + ROCK_HEIGHT + MAX_DISTANCE_BETWEEN_ROCKS);
    }

    //Set the velocity of the north and south rocks
    northRock_.setVelocityX(ROCK_VELOCITY_X);
    northRock_.setVelocityY(ROCK_VELOCITY_Y);

    southRock_.setVelocityX(ROCK_VELOCITY_X);
    southRock_.setVelocityY(ROCK_VELOCITY_Y);

    //The rock is initially has not been passed by the plane
    isPassed_ = false;

    /************************************************************
     Initialize the width and height of the north collision boxes
    *************************************************************/
    for (int i = 0; i < north_CollisionBoxes_.size(); i++) {
        north_CollisionBoxes_[i].w = COLLISION_BOX_NORTH_W[i];
        north_CollisionBoxes_[i].h = COLLISION_BOX_NORTH_H[i];
    }

    /*************************************************************
     Initialize the width and height of the south collision boxes
    *************************************************************/
    for (int i = 0; i < south_CollisionBoxes_.size(); i++) {
        south_CollisionBoxes_[i].w = COLLISION_BOX_SOUTH_W[i];
        south_CollisionBoxes_[i].h = COLLISION_BOX_SOUTH_H[i];
    }

}

void NorthSouthRock::setSourceOffsets(int northSourceOffsetX, int northSourceOffsetY, int southSourceOffsetX, int southSourceOffsetY)
{
    northRock_.setSourceOffsets(northSourceOffsetX, northSourceOffsetY);
    southRock_.setSourceOffsets(southSourceOffsetX, southSourceOffsetY);

}

bool NorthSouthRock::isOutOfBounds()
{
    if (northRock_.getOffsetX() < -110 && southRock_.getOffsetX() < -110)
    {
        return true;
    }

    return false;
}

bool NorthSouthRock::isPassed()
{
    return isPassed_;
}

bool NorthSouthRock::isReached(int planeOffsetX)
{
    if (northRock_.getOffsetX() <= planeOffsetX)
    {
        isPassed_ = true;
        return true;
    }
    return false;
}

void NorthSouthRock::update(int deltaTime)
{
    northRock_.update(deltaTime);
    southRock_.update(deltaTime);

    //Shift the collision boxes
    shiftCollisionBoxes();


    //cout << "North Rock X offset: " << northRock_.getOffsetX() << endl;
    //cout << "South Rock X offset: " << southRock_.getOffsetX() << endl;

}

void NorthSouthRock::draw(Graphics* graphics, Image* image)
{
    northRock_.draw(graphics, image);
    southRock_.draw(graphics, image);
}


/*
 * shift the collision boxes to match the new location of the rock
 */
void NorthSouthRock::shiftCollisionBoxes()
{
    /******************************************************
        Shift the collision boxes for the north rock
    *******************************************************/

    for (int i = 0; i < north_CollisionBoxes_.size(); i++) {
        north_CollisionBoxes_[i].x = northRock_.getOffsetX() + COLLISION_BOX_NORTH_X[i];
        north_CollisionBoxes_[i].y = northRock_.getOffsetY() + COLLISION_BOX_NORTH_Y[i];
    }

    /******************************************************
        Shift the collision boxes for the south rock
    *******************************************************/

    for (int i = 0; i < south_CollisionBoxes_.size(); i++) {
        south_CollisionBoxes_[i].x = southRock_.getOffsetX() + COLLISION_BOX_SOUTH_X[i];
        south_CollisionBoxes_[i].y = southRock_.getOffsetY() + COLLISION_BOX_SOUTH_Y[i];
    }
}
std::vector<SDL_Rect>& NorthSouthRock::getNorthCollisionRects()
{
    return north_CollisionBoxes_;
}
std::vector<SDL_Rect>& NorthSouthRock::getSouthCollisionRects()
{
    return south_CollisionBoxes_;
}
