#include "../include/player.h"
#define ROTATION_SPEED 2.8
#define MOVEMENT_SPEED 4.8

Player::Player()
{
    p_Rotation = 90.0f; // Init rotation
    v_Distance = 400.0f;

    // Init texture. We need to load image, invert colors and then resize it so it would be smaller and i don't need to use scale
    Image p_Img = LoadImage("resources/images/player.png");
    ImageColorInvert(&p_Img);
    ImageResize(&p_Img, 30, 30);
    p_Texture = LoadTextureFromImage(p_Img);
    UnloadImage(p_Img); // Image is no longer needed because it is loaded into Texture2D object and stored in memory

    p_SourceRec = Rectangle{0, 0, (float)p_Texture.width, (float)p_Texture.height};
    p_Origin = Vector2{(float)p_Texture.width / 2, (float)p_Texture.height / 2};
}

void Player::Update()
{
    // Key Movement
    if (IsKeyDown(KEY_A))
    {
        this->p_Rotation -= ROTATION_SPEED;
    }
    if (IsKeyDown(KEY_D))
    {
        this->p_Rotation += ROTATION_SPEED;
    }
    if (IsKeyDown(KEY_W))
    {
        this->p_Pos.x -= MOVEMENT_SPEED * cos(g_Instance.deg_to_rad(p_Rotation));
        this->p_Pos.y -= MOVEMENT_SPEED * sin(g_Instance.deg_to_rad(p_Rotation));
    }
    if (IsKeyDown(KEY_S))
    {
        this->p_Pos.x += MOVEMENT_SPEED * cos(g_Instance.deg_to_rad(p_Rotation));
        this->p_Pos.y += MOVEMENT_SPEED * sin(g_Instance.deg_to_rad(p_Rotation));
    }

    p_Rotation = fmod(360 + fmod(p_Rotation, 360), 360);
    p_DestRec = Rectangle{p_Pos.x, p_Pos.y, (float)p_Texture.width, (float)p_Texture.height};
    p_View = Vector2{(p_DestRec.x - cos(g_Instance.deg_to_rad(p_Rotation)) * v_Distance), (p_DestRec.y - sin(g_Instance.deg_to_rad(p_Rotation)) * v_Distance)};
}
void Player::Draw()
{
    char r_Data[64];
    sprintf(r_Data, "Rotation: %f", p_Rotation);
    char pos_Data[64];
    char view_Data[64];
    sprintf(pos_Data, "PosX: %f | PosY: %f", p_DestRec.x, p_DestRec.y);
    sprintf(view_Data, "VX: %f | VY: %f", p_View.x, p_View.y);

    DrawText(r_Data, 10, 20, 20, WHITE);
    DrawText(pos_Data, 10, 40, 20, WHITE);
    DrawText(view_Data, 10, 60, 20, WHITE);
    DrawTexturePro(p_Texture, p_SourceRec, p_DestRec, p_Origin, p_Rotation - 90.0f, WHITE);
    DrawLineEx(Vector2{p_DestRec.x, p_DestRec.y}, p_View, 1.0f, WHITE);
}