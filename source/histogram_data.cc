#include "histogram_data.h"

HistogramData::HistogramData(Image &image)
{
    this->image = image;
    this->size = image.channels * (1 << image.bitsPerSample);
    this->data = new uint32_t[size]{0};

    for (uint8_t channel = 0; channel < image.channels; channel++)
    {
        for (uint16_t y = 0; y < image.height; y++)
        {
            for (uint16_t x = 0; x < image.width; x++)
            {
                this->data[channel * (1 << image.bitsPerSample) + image.at(x, y, channel)]++;
            }
        }
    }
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

uint32_t HistogramData::get_average()
{
    uint32_t average = 0;

    for (uint16_t i = 0; i < this->size; i++)
        average += this->data[i];
        
    return average / this->size;
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