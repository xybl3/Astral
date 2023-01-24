#pragma once
#include "state.h"

class StateManager
{
private:
    static StateManager *instance;

public:
    static StateManager *getInstance();
    State *state;
    void SwitchState(State *newState);
};