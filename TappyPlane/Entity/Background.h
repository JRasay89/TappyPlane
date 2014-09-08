#ifndef BACKGROUND_H_
#define BACKGROUND_H_

//Core
#include "../Core/Graphics.h"
#include "../Core/Image.h"

//Entity
#include "Entity.h"

class Background : public Entity
{
private:
public:
    Background();
    void draw(Graphics* graphics, Image* image);
};
#endif // BACKGROUND_H_
