#ifndef RGB_PIXEL_H
#define RGB_PIXEL_H

#include "raw_pixel.h"

/**
 * @class RgbPixel 
 * @brief Class to store pixel data in RGB format.
 */
class RgbPixel : public virtual Pixel
{
public:
    /**
     * @brief Create a new RGB pixel with all values initialized to 0.
     * @see RgbPixel(uint8_t *data)
     * @see RgbPixel(uint8_t c1, uint8_t c2, uint8_t c3)
     */
    RgbPixel() : Pixel() {}

    /**
     * @brief Create a new RGB pixel from an array of pixel data.
     * @param data The data of the pixel (the 3 channels as an array).
     * @see RgbPixel()
     * @see RgbPixel(uint8_t c1, uint8_t c2, uint8_t c3)
     */
    RgbPixel(uint8_t *data) : Pixel(data) {}

    /**
     * @brief Create a new RGB pixel with the given values.
     * @param c1 The value of the first channel.
     * @param c2 The value of the second channel.
     * @param c3 The value of the third channel.
     * @see RgbPixel()
     * @see RgbPixel(uint8_t *data)
     */
    RgbPixel(uint8_t c1, uint8_t c2, uint8_t c3) : Pixel(c1, c2, c3) {}

    /**
     * @brief Get the value of the red channel.
     * @return The value of the red channel.
     */
    uint8_t &r();

    /**
     * @brief Get the value of the green channel.
     * @return The value of the green channel.
     */
    uint8_t &g();

    /**
     * @brief Get the value of the blue channel.
     * @return The value of the blue channel.
     */
    uint8_t &b();
};

#endif // RGB_PIXEL_H