#include "../include/statemanager.h"
#include <iostream>
StateManager *StateManager::instance = nullptr;

StateManager *StateManager::getInstance()
{

    std::cout << "Getting instance of StateManager\n";
    if (instance == nullptr)
    {
        instance = new StateManager();
    }
    return instance;
}

void StateManager::SwitchState(State *newState)
{
    this->state = newState;
}