#pragma once
#include "state.h"
#include "raylib.h"
#include "game.h"
#include "buttons.h"
#include "statemanager.h"
#include "player.h"

#include "bullet.h"
#include <list>

class GameScreen : public State
{
private:
    Buttons buttons;
    StateManager s_Manager;
    Player p_Obj;
    std::list<Bullet> bullets;

public:
    void Draw();
    void Update();
    void Shoot();
    GameScreen();
};