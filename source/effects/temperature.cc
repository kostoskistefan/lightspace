#include "temperature.h"

void Temperature::apply(Image &image, double amount)
{
    if (!image.is_valid())
        return;

    for (int y = 0; y < image.height; y++)
    {
        for (int x = 0; x < image.width; x++)
        {
            uint8_t *pixel = image.at(x, y);

            pixel[0] = CLAMP(pixel[0] + amount, 0, 255);
            pixel[2] = CLAMP(pixel[2] - amount, 0, 255);
        }
    }
}