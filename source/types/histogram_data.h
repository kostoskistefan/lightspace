#ifndef HISTOGRAM_DATA_H
#define HISTOGRAM_DATA_H

#include <cstdint>
#include "image.h"

/**
 * @class HistogramData
 * @brief Class to store histogram data from an image.
 */
class HistogramData
{
public:
    /**
     * @brief Default constructor
     * @details Creates a new HistogramData object from an image.
     * @param image The image to create the HistogramData from.
     */
    HistogramData(Image &image);

    /**
     * @brief Destructor
     * @details Deallocates the data array.
     */
    ~HistogramData();

    /**
     * @brief Get the histogram data for a particular channel.
     * @param channel The channel to get the histogram data for.
     * @return A pointer to the histogram data for the given channel.
     */
    uint32_t *at(uint8_t channel);

    /**
     * @brief Get the histogram data at index for a particular channel.
     * @param channel The channel to get the histogram data for.
     * @param colorValue The color brightness for which we count the amount 
     * of pixels containing that brightness for a particular channel.
     * @return A reference to the number of pixels that have a 
     * color represented by the channel and colorValue. 
     * E.g. If channel is 0 (red) and colorValue is 0, 
     * return the number of pixels that have a red value of 0.
     */
    uint32_t &at(uint16_t channel, uint16_t colorValue);

    /**
     * @brief Get the histogram data.
     * @return A pointer to the histogram data.
     */
    uint32_t *get_data();

    /**
     * @brief Get the size of histogram data.
     * @return The size of the histogram data.
     */
    uint32_t get_size();

private:
    Image image;
    uint32_t *data;
    uint32_t size;
};

#endif // HISTOGRAM_DATA_H