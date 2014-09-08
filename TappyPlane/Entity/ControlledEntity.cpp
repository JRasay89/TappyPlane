#include "ControlledEntity.h"

void ControlledEntity::setVelocityX(float velocityX)
{
    velocityX_ = velocityX;
}

void ControlledEntity::setVelocityY(float velocityY)
{
    velocityY_ = velocityY;
}


/*****************************************************
                Getter Methods
*****************************************************/
float ControlledEntity::getVelocityX()
{
    return velocityX_;
}

float ControlledEntity::getVelocityY()
{
    return velocityY_;
}

/*******************************************************
                Virtual Methods
*******************************************************/
void ControlledEntity::update(Input* input, int deltaTime)
{

}

void ControlledEntity::update(int deltaTime)
{

}

void ControlledEntity::draw(Graphics* graphics, Image* image)
{

}

