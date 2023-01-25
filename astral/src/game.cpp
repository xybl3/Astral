#include "../include/game.h"

Game *Game::instance = nullptr;

Game *Game::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Game();
    }
    return instance;
}
void Game::InitGame()
{
    Image logo = LoadImage("resources/logo/logo.png");
    ImageColorInvert(&logo);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    SetWindowIcon(logo);
    SetTargetFPS(WINDOW_FPS);
    UnloadImage(logo);
}

void Game::GameShutDown()
{

    CloseWindow();
}

void Game::CenterWindow()
{

    SetWindowPosition(GetMonitorWidth(GetCurrentMonitor()) / 2 - GetScreenWidth() / 2, GetMonitorHeight(GetCurrentMonitor()) / 2 - GetScreenHeight() / 2);
}

float Game::deg_to_rad(float deg)
{
    return deg * DEG2RAD;
}