#include "Plane.h"

namespace {
    //The width and height of the plane sprite
    const int SPRITE_WIDTH = 88;
    const int SPRITE_HEIGHT = 73;

    const float INITIAL_OFFSET_X = 200.0f;
    const float INITIAL_OFFSET_Y = 156.0f;

    /* Plane's x and y offset on the sprite sheet
     * [0][0-2] = Blue color
     * [1][0-2] = Green color
     * [2][0-2] = Red color
     * [3][0-2] = Yellow color
    */
    const int  SOURCE_SPRITE_OFFSET_X[4][3] = {
                                        {330,372,222}, //Row 0 Blue
                                        {114,216,222}, //Row 1 Green
                                        {216,372,372}, //Row 2 Red
                                        {304,330,330}  //Row 3 Yellow
                                       };
    const int SOURCE_SPRITE_OFFSET_Y[4][3] = {
                                       {1371,1132,1562}, //Row 0 Blue
                                       {1639,1951,1489}, //Row 1 Green
                                       {1878,1059,986}, //Row 2 Red
                                       {1967,1298,1225} //Row 3 Yellow
                                      };

    /*The width, height, x and y value of the collision boxes for the plane
     * Index
     * 0 = Top
     * 1 = Fin
     * 2 = Below Fin
     * 3 = Propeller
     * 4 = Left from Propeller
     * 5 = Bottom
     * 6 = Tire
     */
    //The Width and Height
    const float COLLISION_BOX_W[7] = {56.0f, 23.0f, 15.0f, 10.0f, 10.0f, 30.0f, 20.0f};
    const float COLLISION_BOX_H[7] = {25.0f, 23.0f, 10.0f, 52.0f, 40.0f, 12.0f, 22.0f};
    //The X and Y
    const float COLLISION_BOX_X[7] = {20.0f , 0.0f, 13.0f, 78.0f, 68.0f, 17.0f, 48.0f};
    const float COLLISION_BOX_Y[7] = {0.0f, 10.0f, 32.0f, 15.0f, 25.0f, 50.0f, 50.0f};

    //Falling Gravity
    const float GRAVITY = 9.80f;

    //Jumping velocity
    const float JUMP_VELOCITY = 0.170f;
    const int MAX_JUMP_TIME = 185; //ms



    //The maximum top and bottom boundaries for the plane
    const int SPRITE_MAX_TOP = 0;
    const int SPRITE_MAX_BOTTOM = 407;

    const float FPS = (1000/15);



}

/*
 * This is the plane's constructor
 */
Plane::Plane() : collisionBoxes_(7) {
    //Randomly select color of the plane from the start
    srand(time(0));
    color_ = (Color)(rand() % 4);

    //Initialize the motion of the plane
    motion_ = MOTION_Falling;
    //Initialize the frame counter
    frameCounter_ = 0;

    //Initialize the offset x and offset y of the plane
    //The offset x of the plane is constant
    setOffsetX(INITIAL_OFFSET_X);
    setOffsetY(INITIAL_OFFSET_Y);

    //Set the width and height of the plane
    //Width and height are constant
    setSourceWidth(SPRITE_WIDTH);
    setSourceHeight(SPRITE_HEIGHT);

    //Velocity of plane on the x axis is constant and does not change
    setVelocityX(0.0f);
    setVelocityY(0.0f);

    elapseTime_ = 0;

    puffCloud_.setOffsetY(getOffsetY() + 10.0f);


    //Initialize the collision boxes width and height
    for (int i = 0; i < collisionBoxes_.size(); i++) {
        collisionBoxes_[i].w = COLLISION_BOX_W[i];
        collisionBoxes_[i].h = COLLISION_BOX_H[i];
    }
}

/*
 * This updates the planes offsets and frame
 *
 * @param input is used to check for player input
 * @param deltaTime is used to update the frame of the plane
 */
void Plane::update(Input* input, int deltaTime)
{

    //std::cout << "Delta is: " << deltaTime << std::endl;
    //If player press the space key then make the plane jump
    if (input->isKeyHit(SDLK_SPACE))
    {
        startJump();
    }

    //If plane is falling
    if (motion_ == MOTION_Falling)
    {
        setVelocityY(getVelocityY() + GRAVITY * (deltaTime/1000.0f));
        setOffsetY(getOffsetY() + getVelocityY());
        //Check if the plane has reach the bottom maximum bounds
        if (getOffsetY() >= SPRITE_MAX_BOTTOM)
        {
            setOffsetY(getOffsetY() - getVelocityY());

        }

    }

    //Else if plane is jumping
    else if (motion_ == MOTION_Jumping)
    {
        jump_.update(deltaTime);

        if (jump_.getJumpTimeRemaining() > 0)
        {
            //Set the velocity
            setVelocityY( getVelocityY() + JUMP_VELOCITY);
            setOffsetY(getOffsetY() - getVelocityY());

            //Check if the plane has reach the top maximum bounds
            if (getOffsetY() <= SPRITE_MAX_TOP) {
                setOffsetY(getOffsetY() + getVelocityY());
                //Stop jumping
                stopJump();
            }
        }
        //Max jump is reach
        else
        {

            stopJump();
        }
    }

    elapseTime_ += deltaTime;
    if (elapseTime_ > FPS)
    {
        frameCounter_++;
        if (frameCounter_ == 3)
        {
            frameCounter_ = 0;
        }
        elapseTime_ = 0;
    }

    //Update the puff cloud
    puffCloud_.setOffsetY(getOffsetY() + 10.0f);
    puffCloud_.update(deltaTime);

    //Shift the collision boxes
    shiftCollisionBoxes();
}

void Plane::update(int deltaTime, bool gameOver)
{
    //If the game is over continue to make the plane fall
    if (gameOver)
    {

        setVelocityY(getVelocityY() + GRAVITY * (deltaTime/1000.0f));
        setOffsetY(getOffsetY() + getVelocityY());

        //Check if the plane has reach the bottom maximum bounds
        if (getOffsetY() >= SPRITE_MAX_BOTTOM)
        {
            setOffsetY(getOffsetY() - getVelocityY());

        }
    }

    elapseTime_ += deltaTime;
    if (elapseTime_ > FPS)
    {
        frameCounter_++;
        if (frameCounter_ == 3)
        {
            frameCounter_ = 0;
        }
        elapseTime_ = 0;
    }

    //Update the puff cloud
    puffCloud_.setOffsetY(getOffsetY() + 10.0f);
    puffCloud_.update(deltaTime);


    //Shift the collision boxes
    shiftCollisionBoxes();

}

/*
 * This method takes in a graphics and image objects to be used into
 * drawing the plane sprite onto the screen
 *
 * @param graphics is used for drawing the plane sprite
 * @param image is the sprite sheet where the plane sprite is retrieve from
 */
void Plane::draw(Graphics* graphics, Image* image)
{
    image->draw(getOffsetX(), getOffsetY(), SOURCE_SPRITE_OFFSET_X[color_][frameCounter_], SOURCE_SPRITE_OFFSET_Y[color_][frameCounter_], getSourceWidth(), getSourceHeight(), graphics);
    puffCloud_.draw(graphics, image);
}

/*
 * Start the plane's jumping motion
 * set the the plane's velocity to 0
 */
void Plane::startJump()
{
    motion_ = MOTION_Jumping;
    jump_.activateJump();
    setVelocityY(0.0f);
}

/*
 * Stop the plane's jumping motion
 * resets the values of jump and set the plane's velocity to 0
 */
void Plane::stopJump()
{
    motion_ = MOTION_Falling;
    jump_.deactivateJump();
    jump_.resetJump();
    setVelocityY(0.0f);
}

/*
 * Shift the collision boxes as the plane's location changes
 */
void Plane::shiftCollisionBoxes()
{
    for (int i = 0; i < collisionBoxes_.size(); i++)
    {
        collisionBoxes_[i].x = getOffsetX() + COLLISION_BOX_X[i];
        collisionBoxes_[i].y = getOffsetY() + COLLISION_BOX_Y[i];
    }
}

std::vector<SDL_Rect>& Plane::getCollisionRect()
{
    return collisionBoxes_;
}

/**********************************************************
                Defining Inner Jump class
***********************************************************/
Plane::Jump::Jump()
{
    jumpTimeRemaining_ = MAX_JUMP_TIME;
    isActive_ = false;
}

int Plane::Jump::getJumpTimeRemaining()
{
    return jumpTimeRemaining_;
}

void Plane::Jump::update(int deltaTime)
{
    jumpTimeRemaining_ -= deltaTime;
}
void Plane::Jump::activateJump()
{

    isActive_ = jumpTimeRemaining_ > 0;
}

void Plane::Jump::deactivateJump()
{

    isActive_ = false;
}

void Plane::Jump::resetJump()
{
    jumpTimeRemaining_ = MAX_JUMP_TIME;
}
