#include "histogram_data.h"

#ifdef _OPENMP
#include <omp.h>
#endif

HistogramData::HistogramData(Image &image)
{
    this->image = image;
    this->size = image.channels * image.get_colors_per_pixel();
    this->data = new uint32_t[size]{0};

    this->update();

    for (uint32_t i = 0; i < this->size; i++)
        if (this->data[i] > highestValue)
            highestValue = this->data[i];
}

HistogramData::~HistogramData()
{
    delete[] this->data;
}

uint32_t *HistogramData::at(uint8_t channel)
{
    return &this->data[channel * this->image.get_colors_per_pixel()];
}

uint32_t &HistogramData::at(uint16_t channel, uint16_t colorValue)
{
    return this->data[channel * this->image.get_colors_per_pixel() + colorValue];
}

uint32_t *HistogramData::get_data()
{
    return this->data;
}

uint32_t HistogramData::get_size()
{
    return this->size;
}

uint32_t HistogramData::get_highest_value()
{
    return this->highestValue;
}

void HistogramData::update()
{
    uint32_t colorsPerPixel = image.get_colors_per_pixel();
    std::fill(this->data, this->data + this->size, 0);

#ifdef _OPENMP
#pragma omp parallel for collapse(2)
#endif

    for (uint8_t channel = 0; channel < image.channels; channel++)
        for (uint16_t y = 0; y < image.height; y++)
            for (uint16_t x = 0; x < image.width; x++)
                this->data[channel * colorsPerPixel + image.at(x, y, channel)]++;
}