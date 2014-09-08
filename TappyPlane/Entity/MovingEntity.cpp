#include "MovingEntity.h"

void MovingEntity::setVelocityX(float velocityX)
{
    velocityX_ = velocityX;
}
void MovingEntity::setVelocityY(float velocityY)
{
    velocityY_ = velocityY;
}

float MovingEntity::getVelocityX()
{
    return velocityX_;
}

float MovingEntity::getVelocityY()
{
    return velocityY_;
}


void MovingEntity::update(int deltaTime)
{

}
void MovingEntity::draw(Graphics* graphics, Image* image)
{

}

