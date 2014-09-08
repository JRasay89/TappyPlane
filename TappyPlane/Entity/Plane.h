#ifndef PLANE_H_
#define PLANE_H_

//Entity
#include "ControlledEntity.h"
#include "PuffCloud.h"

#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>

class Plane : public ControlledEntity
{
private:
    //Private inner class
    class Jump
    {
    private:
        bool isActive_;
        int jumpTimeRemaining_;
    public:
        Jump();
        int getJumpTimeRemaining();
        void update(int deltaTime);
        void activateJump();
        void deactivateJump();
        void resetJump();

    };

    /*
    * This enum is used to set the motion of the plane
    */
    enum Motion {
        MOTION_Falling,
        MOTION_Jumping,
    };
    /*
    * This enum will be used for selecting the plane's color
    */
    enum Color {
        COLOR_Blue,
        COLOR_Green,
        COLOR_Red,
        COLOR_Yellow,
    };

    //Variable to hold the plane's jump values
    Jump jump_;
    //Variable to hold the plane's motion
    Motion motion_;
    //Variable to hold the plane's color
    Color color_;

    //Holds the plane's current frame
    int frameCounter_;

    //Holds the amount of time that has passed
    int elapseTime_;

    //Holds the collision rectangle boxes
    std::vector<SDL_Rect> collisionBoxes_;

    //The puff cloud sprite
    PuffCloud puffCloud_;
public:
    Plane();

    void update(Input* input, int deltaTime);
    //Update with no input
    void update(int deltaTime, bool gameOver);

    void draw(Graphics* graphics, Image* image);

    //Jumping
    void startJump();
    void stopJump();

    //Collision boxes
    void shiftCollisionBoxes();
    std::vector<SDL_Rect>& getCollisionRect();

};
#endif // PLANE_H_
