#ifndef NORTHSOUTHROCK_H_
#define NORTHSOUTHROCK_H_

//Entity
#include "Rock.h"

#include <vector>
#include <iostream>
using namespace std;
class NorthSouthRock
{
private:
    Rock northRock_;
    Rock southRock_;

    bool isPassed_;

    //This contains the boxes use for collision detection
    std::vector<SDL_Rect> north_CollisionBoxes_;
    std::vector<SDL_Rect> south_CollisionBoxes_;
public:
    NorthSouthRock();
    void setSourceOffsets(int topSourceOffsetX, int topSourceOffsetY, int bottomSourceOffsetX, int bottomSourceOffsetY);
    bool isOutOfBounds();
    bool isPassed();
    bool isReached(int planeOffsetX);
    void update(int deltaTime);
    void draw(Graphics* graphics, Image* image);

    void shiftCollisionBoxes();
    std::vector<SDL_Rect>& getNorthCollisionRects();
    std::vector<SDL_Rect>& getSouthCollisionRects();

};
#endif // NORTHSOUTHROCK_H_
