#include "image.h"

Image::Image()
{
    this->width = 0;
    this->height = 0;
    this->channels = 0;
    this->rowstride = 0;
    this->pixels = nullptr;
}

Image::Image(const Image &image)
{
    this->pixels = image.pixels;
    this->width = image.width;
    this->height = image.height;
    this->channels = image.channels;
    this->rowstride = image.rowstride;
    this->bitsPerSample = image.bitsPerSample;
}

Image::Image(std::shared_ptr<Gdk::Pixbuf> pixbuf)
{
    this->pixels = pixbuf->get_pixels();
    this->width = pixbuf->get_width();
    this->height = pixbuf->get_height();
    this->channels = pixbuf->get_n_channels();
    this->rowstride = pixbuf->get_rowstride();
    this->bitsPerSample = pixbuf->get_bits_per_sample();
}

bool Image::is_valid()
{
    g_return_val_if_fail(this->pixels != nullptr, false);
    g_return_val_if_fail(this->width > 0, false);
    g_return_val_if_fail(this->height > 0, false);
    g_return_val_if_fail(this->channels > 0, false);
    g_return_val_if_fail(this->rowstride > 0, false);
    g_return_val_if_fail(this->bitsPerSample > 0, false);

    return true;
}

uint8_t *Image::at(uint16_t x, uint16_t y)
{
    return &this->pixels[y * this->rowstride + x * this->channels];
}

void Image::copy_pixels(Image &image)
{
    for (int x = 0; x < image.width; x++)
    {
        for (int y = 0; y < image.height; y++)
        {
            uint8_t *pixel = this->at(x, y);
            uint8_t *pixelToCopy = image.at(x, y);

            for (int channel = 0; channel < image.channels; channel++)
                pixel[channel] = pixelToCopy[channel];
        }
    }
}