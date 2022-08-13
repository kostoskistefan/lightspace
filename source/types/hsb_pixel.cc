#include "hsb_pixel.h"

double &HsbPixel::h()
{
    return Pixel::operator[](0);
}

double &HsbPixel::s()
{
    return Pixel::operator[](1);
}

double &HsbPixel::b()
{
    return Pixel::operator[](2);
}