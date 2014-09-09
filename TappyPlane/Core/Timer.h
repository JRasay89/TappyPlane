#ifndef TIMER_H_
#define TIMER_H_

#include <SDL/SDL.h>

class Timer
{
private:
    int previousTime_;
    int currentTime_;
    int deltaTime_;

public:
    int getTicks();
    int startTimer();
    void setDeltaTimer();
    int getDeltaTime();
};
#endif // TIMER_H_

