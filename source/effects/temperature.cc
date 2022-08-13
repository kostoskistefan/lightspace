#include "temperature.h"
#include "../types/rgb_pixel.h"

void Temperature::apply(Image &image, double amount)
{
    if (!image.is_valid() || amount == 0)
        return;

    for (int y = 0; y < image.height; y++)
    {
        for (int x = 0; x < image.width; x++)
        {
            RgbPixel pixel = image.at(x, y);

            pixel.r() = CLAMP(pixel.r() + amount, 0, 255);
            pixel.b() = CLAMP(pixel.b() - amount, 0, 255);
        }
    }
}