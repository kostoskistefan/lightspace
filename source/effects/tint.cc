#include "tint.h"
#include "../types/rgb_pixel.h"

#ifdef _OPENMP
#include <omp.h>
#endif

void Tint::apply(Image &image, double amount)
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

            pixel.g() = CLAMP(pixel.g() + amount, 0, 255);
        }
    }
}

std::unique_ptr<Effect> Tint::create()
{
    return std::make_unique<Tint>();
}
