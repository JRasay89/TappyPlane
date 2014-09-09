#include "Graphics.h"

bool Graphics::init(int width, int height, bool fullScreen)
{
    screenWidth_ = width;
    screenHeight_ = height;

    if(fullScreen)
    {
        backBuffer_ = SDL_SetVideoMode(screenWidth_, screenHeight_, 32, SDL_SWSURFACE | SDL_FULLSCREEN);
    }
    else
    {
        backBuffer_ = SDL_SetVideoMode(screenWidth_, screenHeight_, 32, SDL_SWSURFACE);
    }

    if(backBuffer_ == NULL)
    {
        printf("Failed to initialize graphics!\n");
        return false;
    }

    return true;

}

void Graphics::clear(int r, int g, int b)
{

    if(backBuffer_ == NULL)
    {
        return;
    }

    Uint32 color;

    color = SDL_MapRGB(backBuffer_->format, r, g, b );

    SDL_FillRect(backBuffer_, NULL, color);

}

/**
 ** Calls SDL_Flip to show the graphics stored on the back buffer to the screen
 **/
void Graphics::flip()
{
    SDL_Flip(backBuffer_);
}

/**
 ** Returns the back buffer
 **/
SDL_Surface* Graphics::getBackBuffer()
{
    return backBuffer_;
}

int Graphics::getScreenWidth()
{
    return screenWidth_;
}

int Graphics::getScreenHeight()
{
    return screenHeight_;
}

