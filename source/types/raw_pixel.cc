#include "raw_pixel.h"
#include <algorithm>

Pixel::Pixel()
{
    this->data = new uint8_t[3];
    this->data[0] = 0;
    this->data[1] = 0;
    this->data[2] = 0;
}

Pixel::Pixel(uint8_t *data)
{
    this->data = data;
}

Pixel::Pixel(uint8_t c1, uint8_t c2, uint8_t c3)
{
    this->data = new uint8_t[3];
    this->data[0] = c1;
    this->data[1] = c2;
    this->data[2] = c3;
}

Pixel &Pixel::operator=(const Pixel &other)
{
    this->data[0] = other.data[0];
    this->data[1] = other.data[1];
    this->data[2] = other.data[2];
    return *this;
}

Pixel &Pixel::operator+=(double value)
{
    // TODO: Change max value to a user defined one
    this->data[0] = std::clamp((int) (this->data[0] + value), 0, 255);
    this->data[1] = std::clamp((int) (this->data[1] + value), 0, 255);
    this->data[2] = std::clamp((int) (this->data[2] + value), 0, 255);
    return *this;
}

Pixel &Pixel::operator*=(double value)
{
    // TODO: Change max value to a user defined one
    this->data[0] = std::clamp((int) (this->data[0] * value), 0, 255);
    this->data[1] = std::clamp((int) (this->data[1] * value), 0, 255);
    this->data[2] = std::clamp((int) (this->data[2] * value), 0, 255);
    return *this;
}

uint8_t &Pixel::operator[](int channel)
{
    return this->data[channel];
}