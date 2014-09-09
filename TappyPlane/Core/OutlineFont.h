#ifndef OUTLINEFONT_H_
#define OUTLINEFONT_H_

#include "Graphics.h"

#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>

#include <string>
using namespace std;

class OutlineFont
{
private:
    TTF_Font* font_;
public:
    OutlineFont();
    void loadFont(string fileName, int ptSize);
    void drawOutlineText(string text, int offsetX, int offsetY, int r, int g, int b, Graphics* graphics);

};
#endif // OUTLINEFONT_H_


