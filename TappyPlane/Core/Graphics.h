#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <SDL/SDL.h>

class Graphics {
private:
    SDL_Surface* backBuffer_;
    int screenWidth_;
    int screenHeight_;

public:
        bool init(int width, int height, bool fullScreen);
        void clear(int r, int g, int b);
        void flip();
        SDL_Surface* getBackBuffer();
        int getScreenWidth();
        int getScreenHeight();
};
#endif // GRAPHICS_H_

