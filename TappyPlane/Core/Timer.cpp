#include "Timer.h"

int Timer::getTicks()
{
    return SDL_GetTicks();
}

int Timer::startTimer()
{
    previousTime_ = getTicks();
}

void Timer::setDeltaTimer()
{
    currentTime_ = getTicks();
    deltaTime_ = (currentTime_ - previousTime_);
    previousTime_ = currentTime_;
}

int Timer::getDeltaTime()
{
    return deltaTime_;


}
