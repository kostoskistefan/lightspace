#include "kernel.h"

kernel::kernel(uint8_t size)
{
    this->size = size;
    this->data = new float[size * size];
}

float kernel::at(uint8_t x, uint8_t y)
{
    return this->data[x * this->size + y];
}