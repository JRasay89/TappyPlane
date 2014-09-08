#ifndef INPUT_H_
#define INPUT_H_

#include <SDL/SDL.h>

class Input {

private:
    bool* keys_;
    bool* prevKeys_;

    int numKeys_;
public:
    void init();
    void free();
    void update();

    bool isKeyHeld(int key);
    bool isKeyHit(int key);
    bool isKeyUp(int key);

};
#endif // INPUT_H_

