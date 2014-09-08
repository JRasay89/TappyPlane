#ifndef IMAGE_H_
#define IMAGE_H_

#include "Graphics.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <string>
using namespace std;

class Image
{
private:
    SDL_Surface* imageSurface_;
public:
    Image();
    bool load(string fileName);
    void draw(float destinationX, float destinationY, int sourceX, int sourceY, int sourceWidth, int sourceHeight, Graphics* g);
    void free();
};
#endif // IMAGE_H_

