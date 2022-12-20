#include "shadows.h"

#include "../color_space.h"
#include <numeric>
#include <cmath>

#ifdef _OPENMP
#include <omp.h>
#endif

void Shadows::apply(Image &image, double amount)
{
    if (!image.is_valid() || amount == 0)
        return;

    const float shadowTone = 0.4 * 255;

    int t[256];
    int lut[256];

    std::iota(std::begin(t), std::end(t), 0);

    double exponent = (amount / 100.0) + 1;

    for (int i = 0; i < 256; i++)
        lut[i] = CLAMP(std::round((1.0 - pow(1.0 - t[i] * 0.00392156863, exponent)) * 255.0), 0, 255);

#ifdef _OPENMP
#pragma omp parallel for collapse(2)
#endif

    for (int y = 0; y < image.height; y++)
    {
        for (int x = 0; x < image.width; x++)
        {
            RgbPixel pixel = image.at(x, y);
            YCbCrPixel ycbcr;

            ColorSpace::rgb_to_ycbcr(pixel, ycbcr);

            double shadowBrightness = 255.0 - ycbcr.y() * 255.0 / shadowTone;

            if (ycbcr.y() >= shadowTone)
                shadowBrightness = 0;

            shadowBrightness *= 1.0 / 255.0;

            ycbcr.y() = (1 - shadowBrightness) * ycbcr.y() + shadowBrightness * lut[(int) ycbcr.y()];

            ColorSpace::ycbcr_to_rgb(ycbcr, pixel);
        }
    }
}
