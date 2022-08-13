#ifndef IMAGE_H
#define IMAGE_H

#include <gdkmm/pixbuf.h>
#include <cstdint>
#include "rgb_pixel.h"

/**
 * @class Image
 * @brief Class to store data from an image.
 */
class Image
{
public:
    /**
     * @brief Default constructor
     * @details Creates a new image with all values initialized to 0.
     * @see Image(const Image &image)
     * @see Image(std::shared_ptr<Gdk::Pixbuf> pixbuf)
     */
    Image();

    /**
     * @brief Copy the data from another image.
     * @details Creates a new image from the data of another image.
     * @param image The image to copy the metadata from.
     * @see Image()
     * @see Image(std::shared_ptr<Gdk::Pixbuf> pixbuf)
     */
    Image(const Image &image);

    /**
     * @brief Create new image from Gdk::Pixbuf.
     * @details Extracts the data from a Gdk::Pixbuf and creates an new image.
     * @param pixbuf The Gdk::Pixbuf to create the image from.
     * @see Image()
     * @see Image(const Image &image)
     */
    Image(std::shared_ptr<Gdk::Pixbuf> pixbuf);

    /**
     * @brief Assignment operator.
     * @details Copies the data from another image.
     * @param image The image to copy the data from.
     * @return A reference to this image.
     */
    Image& operator=(const Image &image);

    /**
     * @brief Check if the image is valid.
     * @details Checks if the image is valid. An image is valid if all metadata is set.
     * @return True if the image is valid, false otherwise.
     */
    bool is_valid();

    /**
     * @brief Get the pixel at a given position.
     * @param x The x position of the pixel.
     * @param y The y position of the pixel.
     * @return A pointer to the pixel at the given position.
     * @see at(uint16_t x, uint16_t y, uint8_t channel)
     */
    RgbPixel at(uint16_t x, uint16_t y);

    /**
     * @brief Get the channel of a pixel at a given position.
     * @param x The x position of the pixel.
     * @param y The y position of the pixel.
     * @param channel The channel to get.
     * @return A reference to the channel of the pixel at the given position.
     * @see at(uint16_t x, uint16_t y)
     */
    uint8_t &at(uint16_t x, uint16_t y, uint8_t channel);

    /**
     * @brief Copy the pixels from another image.
     * @details Modifies the current image by copying the values of each color channel of each pixel from another image passed as a parameter.
     * @param image The image to copy the data from.
     */
    void copy_pixels(Image &image);

    uint8_t *pixels;
    uint16_t width;
    uint16_t height;
    uint8_t channels;
    uint16_t rowstride;
    uint8_t bitsPerSample;
};

#endif // IMAGE_H