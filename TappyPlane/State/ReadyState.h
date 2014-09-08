#ifndef READYSTATE_H_
#define READYSTATE_H_

//Core
#include "../Core/Graphics.h"
#include "../Core/Image.h"
#include "../Core/Input.h"
#include "../Core/OutlineFont.h"

//State
#include "GameState.h"

//Entity
#include "../Entity/Background.h"
#include "../Entity/Plane.h"
#include "../Entity/Ground.h"





class ReadyState : public GameState
{
private:
    Graphics* graphics_;
    Image* image_;
    Input* input_;
    OutlineFont* outlineFont_;

    Background* background_;
    Plane* plane_;
    Ground* ground_;
public:
    void init(Graphics* graphics, Image* image, Input* input, OutlineFont* outlineFont, Background* background, Plane* plane, Ground* ground);
    void update(int deltaTime);
    void draw();

};
#endif // READYSTATE_H_

