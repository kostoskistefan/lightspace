#include "pixel.h"

pixel_ref::pixel_ref(guchar *pixel)
{
    this->r = &pixel[0];
    this->g = &pixel[1];
    this->b = &pixel[2];
}

void pixel_ref::operator=(guint8 value)
{
    *this->r = value;
    *this->g = value;
    *this->b = value;
}
