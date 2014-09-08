#ifndef MOVINGENTITY_H_
#define MOVINGENTITY_H_

#include "../Core/Image.h"
#include "../Core/Graphics.h"

#include "Entity.h"

class MovingEntity : public Entity
{

private:
    float velocityX_;
    float velocityY_;
public:
    void setVelocityX(float velocityX);
    void setVelocityY(float velocityY);

    float getVelocityX();
    float getVelocityY();


    virtual void update(int deltaTime);
    virtual void draw(Graphics* graphics, Image* image);
};
#endif // MOVINGENTITY_H_
