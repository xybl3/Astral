#pragma once
#include "state.h"
#include "raylib.h"
#include "game.h"
#include "buttons.h"

class MainMenu : public State
{
private:
    Texture2D background;
    Buttons buttons;

public:
    void Draw();
    void Update();

    MainMenu();
};