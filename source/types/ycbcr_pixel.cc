#include "ycbcr_pixel.h"

double &YCbCrPixel::y()
{
    return Pixel::operator[](0);
}

double &YCbCrPixel::cb()
{
    return Pixel::operator[](1);
}

double &YCbCrPixel::cr()
{
    return Pixel::operator[](2);
}
