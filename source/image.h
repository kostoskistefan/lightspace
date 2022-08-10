#ifndef IMAGE_H
#define IMAGE_H

#include <gtkmm.h>
#include <cstdint>


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

    uint8_t *pixels;
    uint16_t width;
    uint16_t height;
    uint8_t channels;
    uint16_t rowstride;
    uint8_t bitsPerSample;

    /**
     * @brief Check if the image is valid.
     * @details Checks if the image is valid. An image is valid if all metadata is set.
     * @return True if the image is valid, false otherwise.
     */
    bool is_valid();
};

#endif // IMAGE_H