#ifndef TIMER_H_
#define TIMER_H_

#include <SDL/SDL.h>

//debugging purposes
#include <iostream>

class Timer {

private:
    int previousTime_;
    int currentTime_;
    int deltaTime_;

    int delayTime_;
public:
    int getTicks();
    int startTimer();
    void setDeltaTimer();
    int getDeltaTime();
    int getDelayTime(int fps);
};
#endif // TIMER_H_

