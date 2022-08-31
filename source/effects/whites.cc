#include "whites.h"
#include "../color_space.h"
#include "../math_functions.h"

void Whites::apply(Image &image, double amount)
{
    if (!image.is_valid() || amount == 0)
        return;

    for (int y = 0; y < image.height; y++)
    {
        for (int x = 0; x < image.width; x++)
        {
            RgbPixel pixel = image.at(x, y);
            HsbPixel hsb;

            // Convert pixel to HSB
            ColorSpace::rgb_to_hsb(pixel, hsb);

            // Apply adjustment curve
            hsb.b() = MathFunctions::adjust_whites(hsb.b(), amount);

            // Modify original pixel with new HSB values
            ColorSpace::hsb_to_rgb(hsb, pixel);
        }
    }
}