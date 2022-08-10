#ifndef KERNEL_H
#define KERNEL_H

#include <cstdint>

typedef struct kernel
{
    float *data;
    uint8_t size;
    kernel(uint8_t size);
    float at(uint8_t x, uint8_t y);
} kernel_t;

#endif // KERNEL_H