#include "contrast.h"

void Contrast::apply(Image &image, double amount)
{
    if (!image.is_valid())
        return;

    float factor = (259 * (amount + 255)) / (255 * (259 - amount));

    for (int y = 0; y < image.height; y++)
    {
        for (int x = 0; x < image.width; x++)
        {
            uint8_t *pixel = image.at(x, y);

            for (int channel = 0; channel < image.channels; channel++)
                pixel[channel] = CLAMP(factor * (pixel[channel] - 128) + 128, 0, 255);
        }
    }
}