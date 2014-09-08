#include "Background.h"

namespace
{
    const float INITIAL_OFFSET_X = 0;
    const float INITIAL_OFFSET_Y = 0;

    const int BACKGROUND_WIDTH = 800;
    const int BACKGROUND_HEIGHT = 480;

    const int SOURCE_SPRITE_OFFSET_X = 0;
    const int SOURCE_SPRITE_OFFSET_Y = 355;

}

Background::Background()
{
    setOffsetX(INITIAL_OFFSET_X);
    setOffsetY(INITIAL_OFFSET_Y);

    setSourceWidth(BACKGROUND_WIDTH);
    setSourceHeight(BACKGROUND_HEIGHT);
}
void Background::draw(Graphics* graphics, Image* image)
{
    image->draw(getOffsetX(), getOffsetY(), SOURCE_SPRITE_OFFSET_X, SOURCE_SPRITE_OFFSET_Y, getSourceWidth(), getSourceHeight(), graphics);
}
