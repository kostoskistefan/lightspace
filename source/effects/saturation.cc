#include "saturation.h"

void Saturation::apply(Image &image, double amount)
{
    if (!image.is_valid() || amount == 1)
        return;

    // for (int y = 0; y < image.height; y++)
    // {
    //     for (int x = 0; x < image.width; x++)
    //     {
    //         uint8_t *pixel = image.at(x, y);

    //         rgb_color_t rgbColor = {pixel[0], pixel[1], pixel[2]};

    //         hsb_color_t hsb = rgb_to_hsb(rgbColor);

    //         hsb.s = CLAMP(hsb.s * amount, 0.0f, 1.0f);

    //         rgb_color_t saturatedPixel = hsb_to_rgb(hsb);

    //         pixel[0] = saturatedPixel.r;
    //         pixel[1] = saturatedPixel.g;
    //         pixel[2] = saturatedPixel.b;
    //     }
    // }
}