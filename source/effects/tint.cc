#include "tint.h"

void Tint::apply(Image &image, double amount)
{
    if (!image.is_valid() || amount == 0)
        return;

    for (int y = 0; y < image.height; y++)
    {
        for (int x = 0; x < image.width; x++)
        {
            uint8_t *pixel = image.at(x, y);

            pixel[1] = CLAMP(pixel[1] + amount, 0, 255);
        }
    }
}