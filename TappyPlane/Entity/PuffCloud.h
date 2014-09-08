#ifndef PUFFCLOUD_H_
#define PUFFCLOUD_H_

//Core header files
#include "../Core/Graphics.h"
#include "../Core/Image.h"
#include "../Core/Input.h"

//Entity
#include "Entity.h"

class PuffCloud : public Entity {

private:
    int frameCounter_;
    int elapseTime_;
public:
    PuffCloud();
    void update(int deltaTime);
    void draw(Graphics* graphics, Image* image);
};
#endif // PUFFCLOUD_H_

