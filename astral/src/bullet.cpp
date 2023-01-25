#include "../include/bullet.h"
#include <iostream>
#define MOVEMENT_SPEED 1.0

Bullet::Bullet(Vector2 pos)
{
    this->b_Pos = pos;
};

void Bullet::Draw()
{
    this->b_Pos.x -= MOVEMENT_SPEED;
    this->b_Pos.y -= MOVEMENT_SPEED;
    std::cout << "X:" << b_Pos.x << " Y:" << b_Pos.y << std::endl;
    DrawCircleV(b_Pos, 5, WHITE);
}