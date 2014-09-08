#include "Rock.h"

Rock::Rock()
{

}

void Rock::setSourceOffsets(int sourceOffsetX, int sourceOffsetY)
{
    sourceOffsetX_ = sourceOffsetX;
    sourceOffsetY_ = sourceOffsetY;
}


int Rock::getSourceOffsetX()
{
    return sourceOffsetX_;
}
int Rock::getSourceOffsetY()
{
    return sourceOffsetY_;
}

void Rock::update(int deltaTime)
{
    setOffsetX(getOffsetX() - (getVelocityX() * (deltaTime/1000.0f)));

}
void Rock::draw(Graphics* graphics, Image* image)
{
    image->draw(getOffsetX(), getOffsetY(), getSourceOffsetX(), getSourceOffsetY(), getSourceWidth(), getSourceHeight(), graphics);

}

