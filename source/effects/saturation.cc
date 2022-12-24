#include "saturation.h"
#include "../color_space.h"

#ifdef _OPENMP
#include <omp.h>
#endif

void Saturation::apply(Image &image, double amount)
{
    if (!image.is_valid() || amount == 0)
        return;

    // Remap range [-100, 100] to [0, 2]
    amount = (0.01 * amount) + 1;

#ifdef _OPENMP
#pragma omp parallel for collapse(2)
#endif

    for (int y = 0; y < image.height; y++)
    {
        for (int x = 0; x < image.width; x++)
        {
            RgbPixel pixel = image.at(x, y);
            HsbPixel hsb;

            ColorSpace::rgb_to_hsb(pixel, hsb);

            hsb.s() = CLAMP(hsb.s() * amount, 0, 1);

            ColorSpace::hsb_to_rgb(hsb, pixel);
        }
    }
}

std::unique_ptr<Effect> Saturation::create()
{
    return std::make_unique<Saturation>();
}
