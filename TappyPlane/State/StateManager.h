#ifndef STATEMANAGER_H_
#define STATEMANAGER_H_

//Core
#include "../Core/Graphics.h"

//State
#include "GameState.h"

#include <vector>
using namespace std;

//Forward Declaration
class GameState;

class StateManager
{
private:
    vector<GameState*> states_;
public:
    void addState(GameState* s);
    void popState();
    void clearAll();
    void update(int deltaTime);
    void draw();
    bool isEmpty();
};
#endif // STATEMANAGER_H_
