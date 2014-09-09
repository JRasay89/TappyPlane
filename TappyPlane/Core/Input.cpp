#include "Input.h"

void Input::init()
{
    Uint8* keyBoard = SDL_GetKeyState(&numKeys_);


    keys_ = new bool[numKeys_];
    prevKeys_ = new bool[numKeys_];

    for (int i = 0; i < numKeys_; i++)
    {

       keys_[i] = keyBoard[i];
       prevKeys_[i] = false;
    }

}
void Input::free()
{

    delete[] keys_;
    delete[] prevKeys_;
}

void Input::update()
{

    Uint8* keyBoard = SDL_GetKeyState(&numKeys_);

    for (int i = 0; i < numKeys_; i++)
    {

        prevKeys_[i] = keys_[i];
        keys_[i] = keyBoard[i];
    }


}

bool Input::isKeyHeld(int key)
{

    if (key < 0 || key > numKeys_)
    {
        return false;
    }

    return keys_[key];

}
bool Input::isKeyHit(int key)
{

    if (key < 0 || key > numKeys_)
    {
        return false;
    }

    return (keys_[key] && !prevKeys_[key]);

}

bool Input::isKeyUp(int key)
{

    if (key < 0 || key > numKeys_)
    {
        return false;
    }

    return (prevKeys_[key] && !keys_[key]);

}

