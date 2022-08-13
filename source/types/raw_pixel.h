#ifndef RAW_PIXEL_H
#define RAW_PIXEL_H

#include <cstdint>

/**
 * @class Pixel
 * @brief Class to store pixel data.
 * @note This class is only used as a base class for other
 * types of pixel classes and should not be used directly.
 */
class Pixel
{
public:
    /**
     * @brief Assignment operator.
     * @param other The pixel to assign to this one.
     * @return A reference to this pixel.
     */
    Pixel &operator=(const Pixel &other);

    /**
     * @brief Addition assignment operator.
     * @param value The value to add to each channel of the pixel.
     * @return A reference to this pixel.
     */
    Pixel &operator+=(double value);

    /**
     * @brief Multiplication assignment operator.
     * @param value The value to multiply each channel of the pixel by.
     * @return A reference to this pixel.
     */
    Pixel &operator*=(double value);

    /**
     * @brief Subscript operator.
     * @param channel The channel to get.
     * @return A reference to the particular channel.
     */
    uint8_t &operator[](int channel);

protected:
    /**
     * @brief Create a new pixel with all values initialized to 0.
     * @see Pixel(uint8_t *data)
     * @see Pixel(uint8_t c1, uint8_t c2, uint8_t c3)
     */
    Pixel();

    /**
     * @brief Create a new pixel from an array of pixel data.
     * @param data The data of the pixel (the 3 channels as an array).
     * @see Pixel()
     * @see Pixel(uint8_t c1, uint8_t c2, uint8_t c3)
     */
    Pixel(uint8_t *data);

    /**
     * @brief Create a new pixel with the given values.
     * @param c1 The value of the first channel.
     * @param c2 The value of the second channel.
     * @param c3 The value of the third channel.
     * @see Pixel()
     * @see Pixel(uint8_t *data)
     */
    Pixel(uint8_t c1, uint8_t c2, uint8_t c3);

private:
    // The size is uint8_t because currently
    // Gdk::Pixbuf only supports 8-bit color depth.
    uint8_t *data;
};

#endif // RAW_PIXEL_H