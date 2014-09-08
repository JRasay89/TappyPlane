#include "StateManager.h"

/*
 * Add state into the vector container
*/
void StateManager::addState(GameState* s)
{
    s->setManager(this);
    states_.push_back(s);


}
void StateManager::popState()
{

    if (!states_.empty())
    {
        states_.pop_back();
    }

}
void StateManager::clearAll()
{
    if (!states_.empty())
    {
        states_.clear();
    }
}
void StateManager::update(int deltaTime)
{

    if (!states_.empty())
    {
        states_.back()->update(deltaTime);
    }
}
void StateManager::draw()
{

    if (!states_.empty())
    {
        states_.back()->draw();
    }
}

bool StateManager::isEmpty()
{
    return states_.empty();
}

