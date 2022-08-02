#ifndef PIXEL_H
#define PIXEL_H

#include <gtkmm.h>

typedef struct Pixel {
    guint8 *r;
    guint8 *g;
    guint8 *b;
    Pixel(guchar *pixel);
    void operator=(guint8 value);
} Pixel;

#endif // PIXEL_H
