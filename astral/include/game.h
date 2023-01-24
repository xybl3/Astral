#pragma once
#include "raylib.h"

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 1200
#define WINDOW_TITLE "Astral"
#define WINDOW_FPS 60

class Game
{
private:
    static Game *instance;

public:
    static Game *getInstance();
    void InitGame();
    void GameShutDown();
    void CenterWindow();
};