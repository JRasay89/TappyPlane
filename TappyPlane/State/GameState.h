#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "StateManager.h"

//Forward Declaration
class StateManager;

class GameState
{
private:
    StateManager* stateManager_;
public:
    //Abstract methods
    virtual void update(int deltaTime);
    virtual void draw();

    void setManager(StateManager* stateManager);
    StateManager* getManager();

};
#endif // GAMESTATE_H_

