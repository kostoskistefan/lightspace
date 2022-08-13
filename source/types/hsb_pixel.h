#ifndef HSB_PIXEL_H
#define HSB_PIXEL_H

#include "raw_pixel.h"

/**
 * @class HsbPixel
 * @brief Class to store pixel data in HSB format.
 */
class HsbPixel : public virtual Pixel<double>
{
public:
    /**
     * @brief Create a new HSB pixel with all values initialized to 0.
     * @see HsbPixel(uint8_t *data)
     * @see HsbPixel(uint8_t c1, uint8_t c2, uint8_t c3)
     */
    HsbPixel() : Pixel(1.0) {}

    /**
     * @brief Create a new HSB pixel from an array of pixel data.
     * @param data The data of the pixel (the 3 channels as an array).
     * @see HsbPixel()
     * @see HsbPixel(uint8_t c1, uint8_t c2, uint8_t c3)
     */
    HsbPixel(double *data) : Pixel(data, 1.0) {}

    /**
     * @brief Create a new HSB pixel with the given values.
     * @param c1 The value of the first channel.
     * @param c2 The value of the second channel.
     * @param c3 The value of the third channel.
     * @see HsbPixel()
     * @see HsbPixel(uint8_t *data)
     */
    HsbPixel(double c1, double c2, double c3) : Pixel(c1, c2, c3, 1.0) {}

    /**
     * @brief Get the value of the hue channel.
     * @return The value of the hue channel.
     */
    double &h();

    /**
     * @brief Get the value of the saturation channel.
     * @return The value of the saturation channel.
     */
    double &s();

    /**
     * @brief Get the value of the brightness channel.
     * @return The value of the brightness channel.
     */
    double &b();
};

#endif // HSB_PIXEL_H