#pragma once

#include "raylib.h"

class Bullet
{
private:
    Vector2 b_Pos;

public:
    void Draw();
    Bullet(Vector2 pos);
};