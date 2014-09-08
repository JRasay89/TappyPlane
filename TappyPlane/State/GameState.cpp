#include "GameState.h"

void GameState::update(int deltaTime)
{

}
void GameState::draw()
{

}

void GameState::setManager(StateManager* stateManager)
{
    stateManager_ = stateManager;
}

StateManager* GameState::getManager()
{
    return stateManager_;
}
