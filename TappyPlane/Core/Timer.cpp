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
    //std::cout << "Delta Time is: "<< deltaTime_ << std::endl;

    return deltaTime_;


}

int Timer::getDelayTime(int fps) {

    delayTime_ = (1000/fps) - deltaTime_;
    //std::cout << "Delay Time is: "<< delayTime_ << std::endl;
    return delayTime_;
}
