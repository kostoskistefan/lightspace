#ifndef COLOR_SPACE_CONVERSION_H
#define COLOR_SPACE_CONVERSION_H

#include <gtkmm.h>

typedef struct RgbColor {
    guint8 r;
    guint8 g;
    guint8 b;
    RgbColor();
    RgbColor(guint8 r, guint8 g, guint8 b);
} RgbColor;

typedef struct HsvColor {
    double h;
    double s;
    double v;
    HsvColor();
    HsvColor(double h, double s, double v);
} HsvColor;

RgbColor hsv_to_rgb(HsvColor hsvColor);
HsvColor rgb_to_hsv(RgbColor rgbColor);

#endif
