#pragma once

#include "raylib.h"
#include "game.h"

#include <cmath>
#include <iostream>

class Player
{
private:
    Texture2D p_Texture;

    Rectangle p_SourceRec;
    Rectangle p_DestRec;
    Vector2 p_Origin;

    Game g_Instance; /// @brief Game class Instance
    Vector2 p_Pos = {300, 300};
    float p_Rotation;
    float v_Distance;

public:
    Vector2 p_View;
    void Draw();
    void Update();
    Player();
};