#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include <cstdint>
#include <gtkmm.h>
#include "image.h"

typedef struct kernel
{
    float *data;
    uint8_t size;
    kernel(uint8_t size) {
        this->size = size;
        this->data = new float[this->size * this->size];
    }
} kernel_t;

void convolve(Image image, kernel_t kernel);

#endif // CONVOLUTION_H
