#include "OutlineFont.h"

OutlineFont::OutlineFont()
{

    font_ = NULL;
}

void OutlineFont::loadFont(string fileName, int ptSize)
{

     font_ = TTF_OpenFont(fileName.c_str(), ptSize);


}

void OutlineFont::drawOutlineText(string text, int offsetX, int offsetY, int r, int g, int b, Graphics* graphics)
{
    SDL_Surface* renderedText = NULL;

    SDL_Color color;

    color.r = r;
    color.g = g;
    color.b = b;

    renderedText = TTF_RenderText_Solid(font_, text.c_str(), color);

    SDL_Rect position;

    position.x = offsetX;
    position.y = offsetY;

    SDL_BlitSurface(renderedText, NULL, graphics->getBackBuffer(), &position);
    SDL_FreeSurface(renderedText);
}



