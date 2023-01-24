#include "../include/mainmenu.h"

#include <iostream>

MainMenu::MainMenu()
{
    std::cout << "Loading MainMenu!\n";
    Image temp = LoadImage("resources/images/bg.png");
    ImageResize(&temp, GetScreenWidth(), GetScreenHeight());
    this->background = LoadTextureFromImage(temp);
    UnloadImage(temp);
}

void MainMenu::Update()
{
}

void MainMenu::Draw()
{
    BeginDrawing();
    DrawTexture(this->background, 0, 0, WHITE);
    DrawText(WINDOW_TITLE, GetScreenWidth() / 2 - MeasureText(WINDOW_TITLE, 30), GetScreenHeight() / 4, 50, WHITE);
    DrawFPS(10, 10);

    buttons.DrawTextButton({(float)(GetScreenWidth() / 2), (float)(GetScreenHeight() / 2)}, 300, 50, WHITE, "Start", 30, BLACK);

    ClearBackground(BLANK);
    EndDrawing();
}
