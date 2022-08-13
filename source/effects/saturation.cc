#include "saturation.h"
#include "../color_space.h"

void Saturation::apply(Image &image, double amount)
{
    if (!image.is_valid() || amount == 1)
        return;

    for (int y = 0; y < image.height; y++)
    {
        for (int x = 0; x < image.width; x++)
        {
            RgbPixel pixel = image.at(x, y);
            HsbPixel hsb;
                
            // Convert pixel to HSB
            ColorSpace::rgb_to_hsb(pixel, hsb);

            // Apply saturation
            hsb.s() = CLAMP(hsb.s() * amount, 0, 1);

            // Modify original pixel with new HSB values
            ColorSpace::hsb_to_rgb(hsb, pixel);
        }
    }
}