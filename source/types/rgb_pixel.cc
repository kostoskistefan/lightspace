#include "rgb_pixel.h"

uint8_t &RgbPixel::r()
{
    return Pixel::operator[](0);
}

uint8_t &RgbPixel::g()
{
    return Pixel::operator[](1);
}

uint8_t &RgbPixel::b()
{
    return Pixel::operator[](2);
}