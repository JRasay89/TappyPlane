#ifndef ROCK_H_
#define ROCK_H_

//Entity
#include "MovingEntity.h"

class Rock : public MovingEntity
{
private:
    int sourceOffsetX_; //The x coordinate of the sprite on the sprite sheet
    int sourceOffsetY_; //The y coordinate of the sprite on the sprite sheet
public:
    Rock();

    void setSourceOffsets(int sourceOffsetX, int sourceOffsetY);

    int getSourceOffsetX();
    int getSourceOffsetY();

    void update(int deltaTime);
    void draw(Graphics* graphics, Image* image);

};
#endif // ROCK_H_
