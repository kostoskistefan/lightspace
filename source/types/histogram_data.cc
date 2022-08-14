#include "histogram_data.h"

#ifdef _OPENMP
#include <omp.h>
#endif

HistogramData::HistogramData(Image &image)
{
    int channelSize = (1 << image.bitsPerSample);
    this->image = image;
    this->size = image.channels * channelSize;
    this->data = new uint32_t[size]{0};

#ifdef _OPENMP
#pragma omp parallel for collapse(2)
#endif

    for (uint8_t channel = 0; channel < image.channels; channel++)
        for (uint16_t y = 0; y < image.height; y++)
            for (uint16_t x = 0; x < image.width; x++)
                this->data[channel * channelSize + image.at(x, y, channel)]++;
}

HistogramData::~HistogramData()
{
    delete this->data;
}

uint32_t *HistogramData::at(uint8_t channel)
{
    return &this->data[channel * (1 << this->image.bitsPerSample)];
}

uint32_t &HistogramData::at(uint16_t channel, uint16_t colorValue)
{
    return this->data[channel * (1 << this->image.bitsPerSample) + colorValue];
}

uint32_t *HistogramData::get_data()
{
    return this->data;
}

uint32_t HistogramData::get_size()
{
    return this->size;
}

uint32_t HistogramData::get_channel_size()
{
    return (1 << this->image.bitsPerSample);
}