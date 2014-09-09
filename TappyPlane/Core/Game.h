#ifndef GAME_H_
#define GAME_H

#include "Graphics.h"
#include "Image.h"
#include "Input.h"
#include "OutlineFont.h"
#include "Timer.h"

#include <string>
using namespace std;

class Game
{
private:
    Graphics graphics_;
    Image spriteSheet_;
    Input input_;
    OutlineFont outlineFont_;

    Timer timer_;

    bool isRunning_;
public:
    Game();
    bool initSystem(string title, int width, int height, bool fullScreen);
    void run();
    void freeSystem();
    void quitGame();


    //Getter Methods
    Graphics* getGraphics();
    Image* getImage();
    Input* getInput();
    OutlineFont* getOutlineFont();

    virtual bool init();
    virtual void update(int deltaTime);
    virtual void draw();
    virtual void free();

};
#endif // GAME_H_

