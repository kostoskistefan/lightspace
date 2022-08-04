#ifndef COLOR_SPACE_CONVERSION_H
#define COLOR_SPACE_CONVERSION_H

#include <gtkmm.h>

typedef struct rgb_color {
    guint8 r;
    guint8 g;
    guint8 b;
    rgb_color();
    rgb_color(guint8 value);
    rgb_color(guint8 r, guint8 g, guint8 b);
} rgb_color_t;

typedef struct hsb_color {
    double h;
    double s;
    double b;
    hsb_color();
    hsb_color(double value);
    hsb_color(double h, double s, double b);
} hsb_color_t;

rgb_color_t hsb_to_rgb(hsb_color_t hsbColor);
hsb_color_t rgb_to_hsb(rgb_color_t rgbColor);

#endif
