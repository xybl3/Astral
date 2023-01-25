#pragma once
#include "state.h"
#include "raylib.h"
#include "game.h"
#include "buttons.h"
#include "statemanager.h"

class MainMenu : public State
{
private:
    Texture2D background;
    Buttons buttons;
    StateManager *stateManager = StateManager::getInstance();

public:
    void Draw();
    void Update();

    MainMenu();
};