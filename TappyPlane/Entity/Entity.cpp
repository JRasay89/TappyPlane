#include "Entity.h"


void Entity::setOffsetX(float offsetX)
{
    offsetX_ = offsetX;
}
void Entity::setOffsetY(float offsetY)
{
    offsetY_ = offsetY;
}

void Entity::setSourceWidth(int width)
{
    sourceWidth_ = width;
}
void Entity::setSourceHeight(int sourceHeight)
{
    sourceHeight_ = sourceHeight;
}

float Entity::getOffsetX()
{
    return offsetX_;
}
float Entity::getOffsetY()
{
    return offsetY_;
}
int Entity::getSourceWidth()
{
    return sourceWidth_;
}
int Entity::getSourceHeight()
{
    return sourceHeight_;
}

