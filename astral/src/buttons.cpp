#include "../include/buttons.h"

bool Buttons::DrawTextButton(Vector2 pos, int width, int height, Color bgColor, char text[], int fontSize, Color foreColor)
{
    Rectangle buttonRec = {pos.x - width / 2, pos.y - height / 2, width, height};

    DrawRectangleRec(buttonRec, bgColor);
    DrawText(text, pos.x - (MeasureText(text, fontSize) / 2), pos.y - height / 3, fontSize, RED);
    return false;
}