#include "../include/mainmenu.h"
#include "../include/gamescreen.h"

#include <iostream>

GameScreen::GameScreen()
{
    std::cout << "Loading GameScreen!\n";
    this->bullets = {};
}

void GameScreen::Shoot()
{
    this->bullets.push_back(Bullet{p_Obj.p_View});
}

void GameScreen::Update()
{
    p_Obj.Update();
    if (IsKeyPressed(KEY_SPACE))
    {
        std::cout << "Shoot!" << std::endl;
        this->Shoot();
    }
}

void GameScreen::Draw()
{

    BeginDrawing();
    // Bullet drawing
    for (auto bullet : this->bullets)
    {
        bullet.Draw();
    }

    DrawFPS(10, 10);
    //
    p_Obj.Draw();
    //
    ClearBackground(BLANK);
    EndDrawing();
}
