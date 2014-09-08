#ifndef GROUND_H_
#define GROUND_H_

#include "MovingEntity.h"

#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

class Ground : public MovingEntity
{
private:
    //Collision boxes for the ground
    std::vector<SDL_Rect> collisionBoxes_;
    std::vector<SDL_Rect> collisionBoxes_Loop_;

    enum Type {
        TYPE_Dirt,
        TYPE_Grass,
        TYPE_ICE,
        TYPE_SNOW,
    };

    Type type_;
public:
    Ground();
    void update(int deltaTime);
    void draw(Graphics* graphics, Image* image);

    void shiftCollisionBoxes();
    std::vector<SDL_Rect>& getCollisionRect();
    std::vector<SDL_Rect>& getCollisionRectLoop();

    int getType();
};
#endif // GROUND_H_
