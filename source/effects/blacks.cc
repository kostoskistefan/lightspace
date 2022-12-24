#include "blacks.h"
#include "../color_space.h"
#include <cmath>

#ifdef _OPENMP
#include <omp.h>
#endif

void Blacks::apply(Image &image, double amount)
{
    if (!image.is_valid() || amount == 0)
        return;

    amount *= 100.0 / 255.0;

#ifdef _OPENMP
#pragma omp parallel for collapse(2)
#endif

    for (int y = 0; y < image.height; y++)
    {
        for (int x = 0; x < image.width; x++)
        {
            RgbPixel pixel = image.at(x, y);
            YCbCrPixel hsb;

            ColorSpace::rgb_to_ycbcr(pixel, hsb);

            double additiveAmount = std::pow((hsb.y() / 255.0) - 1, 8);

            hsb.y() = CLAMP(hsb.y() + amount * additiveAmount, 0, 255);

            ColorSpace::ycbcr_to_rgb(hsb, pixel);
        }
    }
}

std::unique_ptr<Effect> Blacks::create()
{
    return std::make_unique<Blacks>();
}