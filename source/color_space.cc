#include "color_space.h"
#include <cmath>
#include <gtkmm.h>

#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))

void ColorSpace::rgb_to_hsb(RgbPixel &rgb, HsbPixel &hsb)
{
    int min = MIN(rgb.r(), MIN(rgb.g(), rgb.b()));
    int max = MAX(rgb.r(), MAX(rgb.g(), rgb.b()));

    hsb.b() = max / 255.0f;

    if (max == 0)
        hsb.s() = 0;

    else
        hsb.s() = ((float)(max - min)) / ((float)max);

    if (hsb.s() == 0)
        hsb.h() = 0;

    else
    {
        float delta = (max - min) * 6;

        if (rgb.r() == max)
            hsb.h() = (rgb.g() - rgb.b()) / delta;

        else if (rgb.g() == max)
            hsb.h() = 1.0f / 3 + (rgb.b() - rgb.r()) / delta;

        else
            hsb.h() = 2.0f / 3 + (rgb.r() - rgb.g()) / delta;

        if (hsb.h() < 0)
            hsb.h()++;
    }
}

void ColorSpace::hsb_to_rgb(HsbPixel &hsb, RgbPixel &rgb)
{
    if (hsb.s() == 0)
    {
        rgb.r() = hsb.b() * 255;
        rgb.g() = hsb.b() * 255;
        rgb.b() = hsb.b() * 255;
        return;
    }

    hsb.h() = hsb.h() - std::floor(hsb.h());

    int i = std::floor(hsb.h() * 6);

    float f = hsb.h() * 6 - i;
    float p = hsb.b() * (1 - hsb.s());
    float q = hsb.b() * (1 - f * hsb.s());
    float t = hsb.b() * (1 - (1 - f) * hsb.s());

    p *= 255;
    q *= 255;
    t *= 255;
    hsb.b() *= 255;

    switch (i)
    {
        case 0:
            rgb.r() = hsb.b();
            rgb.g() = t;
            rgb.b() = p;
            break;
        case 1:
            rgb.r() = q;
            rgb.g() = hsb.b();
            rgb.b() = p;
            break;
        case 2:
            rgb.r() = p;
            rgb.g() = hsb.b();
            rgb.b() = t;
            break;
        case 3:
            rgb.r() = p;
            rgb.g() = q;
            rgb.b() = hsb.b();
            break;
        case 4:
            rgb.r() = t;
            rgb.g() = p;
            rgb.b() = hsb.b();
            break;
        case 5:
            rgb.r() = hsb.b();
            rgb.g() = p;
            rgb.b() = q;
            break;
    }
}

void ColorSpace::rgb_to_ycbcr(RgbPixel &rgb, YCbCrPixel &ycbcr)
{
    ycbcr.y()  =     0.299 * rgb.r() +    0.587 * rgb.g() +    0.114 * rgb.b();
    ycbcr.cb() = -0.168736 * rgb.r() - 0.331264 * rgb.g() +      0.5 * rgb.b();
    ycbcr.cr() =       0.5 * rgb.r() - 0.418688 * rgb.g() - 0.081312 * rgb.b();
}

void ColorSpace::ycbcr_to_rgb(YCbCrPixel &ycbcr, RgbPixel &rgb)
{
    rgb.r() = CLAMP(std::round(ycbcr.y() +                            1.402 * ycbcr.cr()), 0, 255);
    rgb.g() = CLAMP(std::round(ycbcr.y() - 0.344136 * ycbcr.cb() - 0.714136 * ycbcr.cr()), 0, 255);
    rgb.b() = CLAMP(std::round(ycbcr.y() +    1.772 * ycbcr.cb()                        ), 0, 255);
}
