#ifndef PIXEL_H
#define PIXEL_H

#include <gtkmm.h>

typedef struct pixel_ref {
    guint8 *r;
    guint8 *g;
    guint8 *b;
    pixel_ref(guchar *pixel);
    void operator=(guint8 value);
} pixel_ref_t;

#endif // PIXEL_H
