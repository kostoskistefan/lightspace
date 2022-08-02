#include "color_space.h"

RgbColor::RgbColor() {}
RgbColor::RgbColor(guint8 r, guint8 g, guint8 b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

HsvColor::HsvColor() {}
HsvColor::HsvColor(double h, double s, double v)
{
    this->h = h;
    this->s = s;
    this->v = v;
}

RgbColor hsv_to_rgb(HsvColor hsvColor)
{
    double c = hsvColor.v * hsvColor.s;
    double x = c * (1 - fabs(fmod(hsvColor.h / 60.0, 2) - 1));
    double m = hsvColor.v - c;
    
    double r, g, b;
    
    if (hsvColor.h >= 0 && hsvColor.h < 60)
    {
        r = c;
        g = x;
        b = 0;
    }
    else if (hsvColor.h >= 60 && hsvColor.h < 120)
    {
        r = x;
        g = c;
        b = 0;
    }
    else if (hsvColor.h >= 120 && hsvColor.h < 180)
    {
        r = 0;
        g = c;
        b = x;
    }
    else if (hsvColor.h >= 180 && hsvColor.h < 240)
    {
        r = 0;
        g = x;
        b = c;
    }
    else if (hsvColor.h >= 240 && hsvColor.h < 300)
    {
        r = x;
        g = 0;
        b = c;
    }
    else if (hsvColor.h >= 300 && hsvColor.h < 360)
    {
        r = c;
        g = 0;
        b = x;
    }
    
    return RgbColor(
        (r + m) * 255,
        (g + m) * 255,
        (b + m) * 255);
}

HsvColor rgb_to_hsv(RgbColor rgbColor)
{
    double r = rgbColor.r / 255.0;
    double g = rgbColor.g / 255.0;
    double b = rgbColor.b / 255.0;
    
    double min = MIN(r, MIN(g, b));
    double max = MAX(r, MAX(g, b));
    double delta = max - min;
    
    double h = 0;
    double s = 0;
    double v = max;
    
    if (delta == 0)
    {
        h = 0;
        s = 0;
    }
    else
    {
        s = delta / max;
        
        if (r == max)
            h = (g - b) / delta;
        else if (g == max)
            h = 2 + (b - r) / delta;
        else if (b == max)
            h = 4 + (r - g) / delta;
        
        h *= 60;
        if (h < 0)
            h += 360;
    }
    
    return HsvColor(h, s, v);
}
