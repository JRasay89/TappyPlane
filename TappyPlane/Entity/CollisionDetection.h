#ifndef COLLISIONDETECTION_H_
#define COLLISIONDETECTION_H_

//SDL
#include <SDL/SDL.h>

//Core
#include "../Core/Graphics.h"

//Entity
#include "Plane.h"
#include "Ground.h"
#include "NorthSouthRock.h"

//Vector
#include <vector>

class CollisionDetection
{
private:
public:
    bool detectCollision(std::vector<SDL_Rect>& boxA, std::vector<SDL_Rect>& boxB);

    //These functions is used to show the collision boxes of the object
    void drawCollisionBox(Graphics* graphics, std::vector<SDL_Rect>& collisionBox);
    void drawRect(Graphics* graphics, int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b);
    void FillRect(SDL_Surface* surface, int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b);

};
#endif // COLLISIONDETECTION_H_

