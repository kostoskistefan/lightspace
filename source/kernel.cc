#include "kernel.h"

Kernel::Kernel(uint8_t size)
{
    this->size = size;
    this->data = new float[size * size];
}

Kernel::~Kernel()
{
    delete this->data;
}

float &Kernel::at(uint8_t x, uint8_t y)
{
    return this->data[x * this->size + y];
}

uint8_t Kernel::get_size()
{
    return this->size;
}