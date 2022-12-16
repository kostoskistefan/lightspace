#ifndef YCBCR_PIXEL_H
#define YCBCR_PIXEL_H

#include "raw_pixel.h"

/**
 * @class YCbCrPixel
 * @brief Class to store pixel data in YCbCr format.
 */
class YCbCrPixel : public virtual Pixel<double>
{
public:
    /**
     * @brief Create a new YCbCr pixel with all values initialized to 0.
     * @see YCbCrPixel(uint8_t *data)
     * @see YCbCrPixel(uint8_t c1, uint8_t c2, uint8_t c3)
     */
    YCbCrPixel() : Pixel(255.0) {}

    /**
     * @brief Create a new YCbCr pixel from an array of pixel data.
     * @param data The data of the pixel (the 3 channels as an array).
     * @see YCbCrPixel()
     * @see YCbCrPixel(uint8_t c1, uint8_t c2, uint8_t c3)
     */
    YCbCrPixel(double *data) : Pixel(data, 255.0) {}

    /**
     * @brief Create a new YCbCr pixel with the given values.
     * @param y The value of the first channel.
     * @param cb The value of the second channel.
     * @param cr The value of the third channel.
     * @see YCbCrPixel()
     * @see YCbCrPixel(uint8_t *data)
     */
    YCbCrPixel(double y, double cb, double cr) : Pixel(y, cb, cr, 255.0) {}

    /**
     * @brief Get the value of the y channel.
     * @return The value of the y channel.
     */
    double &y();

    /**
     * @brief Get the value of the cb channel.
     * @return The value of the cb channel.
     */
    double &cb();

    /**
     * @brief Get the value of the cr channel.
     * @return The value of the cr channel.
     */
    double &cr();
};

#endif // YCBCR_PIXEL_H
