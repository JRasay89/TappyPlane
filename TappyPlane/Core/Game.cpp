#include "Game.h"

Game::Game()
{
}

bool Game::initSystem(string title, int width, int height, bool fullScreen)
{

    //Initialize SDL
    if(SDL_Init( SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }

    //Initialize font
    if(TTF_Init() < 0)
    {
        return false;
    }

    //Initialize the graphics
    if (!graphics_.init(width, height, fullScreen)) {
        return false;
    }

    //Initialize the input
    input_.init();

    //Load the sprite sheet
    if (!spriteSheet_.load("Resource/SpriteSheet/sheet.png"))
    {
        return false;
    }

    //Load the font
    outlineFont_.loadFont("Resource/OutlineFont/kenvector_future.ttf",24);

    //Set the title
    SDL_WM_SetCaption(title.c_str(), NULL);





    return true;

}
/*
 * Starts the game
 */
void Game::run()
{

    timer_.startTimer();
    isRunning_ = true;
    while(isRunning_){

        //Check for termination event
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {

            if(event.type == SDL_QUIT)
            {
                isRunning_ = false;
            }
        }

        input_.update();


        //logic

        //Get the delta time
        timer_.setDeltaTimer();
        //Update the game and pass the delta time
        update(timer_.getDeltaTime());


        //Render
        //Clear the screen
        graphics_.clear(0,0,0);
        draw();


        //Display the picture on the screen
        graphics_.flip();
    }

    //Free the resources and quit the system
    free();
    freeSystem();

}

void Game::freeSystem()
{
    spriteSheet_.free();
    input_.free();
    TTF_Quit();
    SDL_Quit();
}

void Game::quitGame()
{

    isRunning_ = false;
}

/*
 * Use to regulate the fps of the game
 *
 */
void Game::delay(int delayTime)
{
    if (delayTime > 0)
    {
        SDL_Delay(delayTime);
    }

}


/*
 * Returns the graphics object to be used to draw objects into the buffer
 * and show the graphics on the screen
 *
 * @return the graphics of the game
 */
Graphics* Game::getGraphics()
{
    return &graphics_;
}

/*
 * @return the image being used for the game
 */
Image* Game::getImage()
{
    return &spriteSheet_;
}

Input* Game::getInput() {
    return &input_;
}

OutlineFont* Game::getOutlineFont()
{

    return &outlineFont_;
}

bool Game::init()
{


}
void Game::update(int deltaTime)
{


}

void Game::draw()
{



}

void Game::free()
{

}
