#include "PuffCloud.h"

namespace {


    /* The width, height, x, and y value of the puff cloud sprite
     * 0 = Small
     * 1 = Large
     */
    const int CLOUD_WIDTH[2] = {25,42};
    const int CLOUD_HEIGHT[2] = {21,35};

    const int SOURCE_SPRITE_OFFSET_X[2] = {196,114};
    const int SOURCE_SPRITE_OFFSET_Y[2] = {1250,1712};
    //The x position of the plane on the screen
    const float INITIAL_OFFSET_X = 145;

    const float FPS = (1000/15);

}

PuffCloud::PuffCloud()
{
    frameCounter_ = 0;
    elapseTime_ = 0;

    //The x offset of the cloud is constant and does not change
    setOffsetX(INITIAL_OFFSET_X);

    //Set the initial source width of the cloud
    setSourceWidth(CLOUD_WIDTH[frameCounter_]);
    setSourceHeight(CLOUD_HEIGHT[frameCounter_]);


}

void PuffCloud::update(int deltaTime)
{
    elapseTime_ += deltaTime;
    if (elapseTime_ > FPS)
    {
        frameCounter_++;
        if (frameCounter_ == 2)
        {
            frameCounter_ = 0;
        }

        setSourceWidth(CLOUD_WIDTH[frameCounter_]);
        setSourceHeight(CLOUD_HEIGHT[frameCounter_]);

        //Resets elapse time
        elapseTime_ = 0;
    }
}

void PuffCloud::draw(Graphics* graphics, Image* image)
{
    image->draw(getOffsetX(), getOffsetY(), SOURCE_SPRITE_OFFSET_X[frameCounter_], SOURCE_SPRITE_OFFSET_Y[frameCounter_], getSourceWidth(), getSourceHeight(), graphics);
}
