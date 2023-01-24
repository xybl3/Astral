#include "../include/raylib.h"
#include "../include/game.h"
#include "../include/mainmenu.h"
#include "../include/statemanager.h"

int main()
{
    Game *game = Game::getInstance();
    StateManager *stateManager = StateManager::getInstance();

    stateManager->state = new MainMenu();
    game->InitGame();
    game->CenterWindow();

    while (!WindowShouldClose())
    {
        stateManager->state->Update();
        stateManager->state->Draw();
    }
    game->GameShutDown();
}