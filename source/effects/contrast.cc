#include "contrast.h"
#include "../types/rgb_pixel.h"

#ifdef _OPENMP
#include <omp.h>
#endif

void Contrast::apply(Image &image, double amount)
{
    if (!image.is_valid() || amount == 0)
        return;

    float factor = (259 * (amount + 255)) / (255 * (259 - amount));

#ifdef _OPENMP
#pragma omp parallel for collapse(2)
#endif

    for (int y = 0; y < image.height; y++)
    {
        for (int x = 0; x < image.width; x++)
        {
            RgbPixel pixel = image.at(x, y);

            for (int channel = 0; channel < image.channels; channel++)
                pixel[channel] = CLAMP(factor * (pixel[channel] - 128) + 128, 0, 255);
        }
    }
}