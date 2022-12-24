#include "highlights.h"

#include "../color_space.h"
#include <numeric>
#include <cmath>

#ifdef _OPENMP
#include <omp.h>
#endif

void Highlights::apply(Image &image, double amount)
{
    if (!image.is_valid() || amount == 0)
        return;

    const float highlightTone = 255 - 0.4 * 255;

    int t[256];
    int lut[256];

    std::iota(std::begin(t), std::end(t), 0);

    double exponent = 1 - (amount / 100.0);

    for (int i = 0; i < 256; i++)
        lut[i] = CLAMP(std::round(pow(t[i] * 0.00392156863, exponent) * 255), 0, 255);

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

            double highlightBrightness = 255.0 - (255.0 - ycbcr.y()) * 255.0 / (255.0 - highlightTone);

            if (ycbcr.y() <= highlightTone)
                highlightBrightness = 0;

            highlightBrightness *= 1.0 / 255.0;

            ycbcr.y() = (1 - highlightBrightness) * ycbcr.y() + highlightBrightness * lut[(int) ycbcr.y()];

            ColorSpace::ycbcr_to_rgb(ycbcr, pixel);
        }
    }
}

std::unique_ptr<Effect> Highlights::create()
{
    return std::make_unique<Highlights>();
}
