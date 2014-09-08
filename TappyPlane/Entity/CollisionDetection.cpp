#include "CollisionDetection.h"

/*
 * Detect the collision between two objects by comparing their collision boxes
 * if one of boxA's collision box is inside boxB's collision box, then a collision has occured.
 *
 * @param boxA is one of the collision box to be compared
 * @param boxB is the other collision box to be compared
 */
bool CollisionDetection::detectCollision(std::vector<SDL_Rect>& boxA, std::vector<SDL_Rect>& boxB)
{
    float leftA, leftB;
    float rightA, rightB;
    float topA, topB;
    float bottomA, bottomB;

    for (int i = 0; i < boxA.size(); i++)
    {

        leftA = boxA[i].x;
        rightA = boxA[i].x + boxA[i].w;
        topA = boxA[i].y;
        bottomA = boxA[i].y + boxA[i].h;

        for (int j = 0; j < boxB.size(); j++)
        {
            leftB = boxB[j].x;
            rightB = boxB[j].x + boxB[j].w;
            topB = boxB[j].y;
            bottomB = boxB[j].y + boxB[j].h;

            if (( (bottomA <= topB) || (topA >= bottomB) || (rightA <= leftB) || (leftA >= rightB) ) == false)
            {

                //A collision has been found
                return true;
            }
        }

    }
    return false;
}

/*****************************
    Show the collision box
******************************/


/*
 * Draws the collision box
 *
 * @param graphics is used to draw the boxes to the screen
 * @param collisionBox are the boxes that will be drawn to the screen
 */
void CollisionDetection::drawCollisionBox(Graphics* graphics, std::vector<SDL_Rect>& collisionBox)
{
    for (int i = 0; i < collisionBox.size(); i++)
    {
        drawRect(graphics,collisionBox[i].x, collisionBox[i].y, collisionBox[i].w, collisionBox[i].h, 255, 0, 0);
    }
}

void CollisionDetection::drawRect(Graphics* graphics, int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b)
{
    //Top
    FillRect(graphics->getBackBuffer(), x, y, width, 1, r, g, b);
    //Bottom
    FillRect(graphics->getBackBuffer(), x, y+height-1, width, 1, r, g, b);
    //Left
    FillRect(graphics->getBackBuffer(), x, y, 1, height, r, g, b);
    //Right
    FillRect(graphics->getBackBuffer(), x+width-1, y, 1, height, r, g, b);
}

void CollisionDetection::FillRect(SDL_Surface* surface, int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b)
{
    Uint32 color;

    color = SDL_MapRGB(surface->format, r, g, b);

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    SDL_FillRect(surface, &rect, color);
}
