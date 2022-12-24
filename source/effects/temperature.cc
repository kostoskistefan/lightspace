#include "temperature.h"
#include "../types/rgb_pixel.h"

#ifdef _OPENMP
#include <omp.h>
#endif

void Temperature::apply(Image &image, double amount)
{
    if (!image.is_valid() || amount == 0)
        return;

#ifdef _OPENMP
#pragma omp parallel for collapse(2)
#endif

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

std::unique_ptr<Effect> Temperature::create()
{
    return std::make_unique<Temperature>();
}
