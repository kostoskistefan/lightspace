#include "pixel.h"

Pixel::Pixel(guchar *pixel)
{
    this->r = &pixel[0];
    this->g = &pixel[1];
    this->b = &pixel[2];
}

void Pixel::operator=(guint8 value)
{
    *this->r = value;
    *this->g = value;
    *this->b = value;
}
