#ifndef CONTROLLEDENTITY_H_
#define CONTROLLEDENTITY_H_

//Core
#include "../Core/Graphics.h"
#include "../Core/Image.h"
#include "../Core/Input.h"

#include "Entity.h"

/*
 * The controlled entity is an entity that takes in input from the player
 */
class ControlledEntity : public Entity
{
private:
    float velocityX_;
    float velocityY_;


public:
    void setVelocityX(float velocityX);
    void setVelocityY(float velocityY);

    float getVelocityX();
    float getVelocityY();


    virtual void update(Input* input, int deltaTime);
    virtual void update(int deltaTime);
    virtual void draw(Graphics* graphics, Image* image);

};
#endif // CONTROLLEDENTITY_H_

