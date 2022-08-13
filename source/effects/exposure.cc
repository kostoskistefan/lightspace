#include "exposure.h"

void Exposure::apply(Image &image, double amount)
{
    if (!image.is_valid() || amount == 0)
        return;

    double value = pow(2, amount);

    for (int y = 0; y < image.height; y++)
    {
        for (int x = 0; x < image.width; x++)
        {
            uint8_t *pixel = image.at(x, y);

            for (int channel = 0; channel < image.channels; channel++)
                pixel[channel] = CLAMP(pixel[channel] * value, 0, 255);
        }
    }
}