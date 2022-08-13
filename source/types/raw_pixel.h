#ifndef RAW_PIXEL_H
#define RAW_PIXEL_H

#include <cstdint>

/**
 * @class Pixel
 * @brief Class to store pixel data.
 * @tparam T The type of the pixel data (either uint8_t or double).
 * @note This class is only used as a base class for other
 * types of pixel classes and should not be used directly.
 */
template <typename T>
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
    T &operator[](int channel);

protected:
    /**
     * @brief Create a new pixel with all values initialized to 0.
     * @param maxValue The maximum value that a pixel can have.
     * @see Pixel(T *data, T maxValue)
     * @see Pixel(T c1, T c2, T c3, T maxValue)
     */
    Pixel(T maxValue);

    /**
     * @brief Create a new pixel from a pixel data array.
     * @param data The data of the pixel (the 3 channels as an array).
     * @param maxValue The maximum value that a pixel can have.
     * @see Pixel(T maxValue)
     * @see Pixel(T c1, T c2, T c3, T maxValue)
     */
    Pixel(T *data, T maxValue);

    /**
     * @brief Create a new pixel with given values for each channel.
     * @param c1 The value of the first channel.
     * @param c2 The value of the second channel.
     * @param c3 The value of the third channel.
     * @param maxValue The maximum value that a pixel can have.
     * @see Pixel(T maxValue)
     * @see Pixel(T *data, T maxValue)
     */
    Pixel(T c1, T c2, T c3, T maxValue);

    Pixel(Pixel &other);

private:
    T *data;
    T maxValue;
};

#endif // RAW_PIXEL_H