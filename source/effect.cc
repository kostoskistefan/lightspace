#include "effect.h"
#include "utilities.h"
#include <omp.h>

bool pixbuf_is_valid(Glib::RefPtr<Gdk::Pixbuf> pixbuf)
{
    g_return_val_if_fail(pixbuf != nullptr, false);

    g_return_val_if_fail(pixbuf->get_colorspace() == Gdk::Colorspace::RGB, false);
    g_return_val_if_fail(pixbuf->get_bits_per_sample() == 8, false);
    g_return_val_if_fail(pixbuf->get_n_channels() == 3, false);

    return true;
}

void apply_temperature(double value)
{
    auto pixbuf = ImageProcessor::get_instance().get_pixbuf();

    if (!pixbuf_is_valid(pixbuf))
        return;

    int height = pixbuf->get_height();
    int width = pixbuf->get_width();
    int rowstride = pixbuf->get_rowstride();
    int n_channels = pixbuf->get_n_channels();
    guchar *pixels = pixbuf->get_pixels();

#pragma omp parallel for num_threads(4) collapse(2)

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            guchar *pixel = &pixels[y * rowstride + x * n_channels];
            pixel[0] = CLAMP(pixel[0] + value, 0, 255);
            pixel[2] = CLAMP(pixel[2] - value, 0, 255);
        }
    }
}

void apply_tint(double value)
{
    auto pixbuf = ImageProcessor::get_instance().get_pixbuf();

    if (!pixbuf_is_valid(pixbuf))
        return;

    int height = pixbuf->get_height();
    int width = pixbuf->get_width();
    int rowstride = pixbuf->get_rowstride();
    int n_channels = pixbuf->get_n_channels();
    guchar *pixels = pixbuf->get_pixels();

#pragma omp parallel for num_threads(4) collapse(2)

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            guchar *pixel = &pixels[y * rowstride + x * n_channels];
            pixel[1] = CLAMP(pixel[1] + value, 0, 255);
        }
    }
}

void apply_exposure(double value)
{
    auto pixbuf = ImageProcessor::get_instance().get_pixbuf();

    if (!pixbuf_is_valid(pixbuf))
        return;

    int height = pixbuf->get_height();
    int width = pixbuf->get_width();
    int rowstride = pixbuf->get_rowstride();
    int n_channels = pixbuf->get_n_channels();
    guchar *pixels = pixbuf->get_pixels();

#pragma omp parallel for num_threads(4) collapse(2)

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            guchar *pixel = &pixels[y * rowstride + x * n_channels];

            for (int k = 0; k < n_channels; k++)
                pixel[k] = CLAMP(pixel[k] * (fastPow(2, value)), 0, 255);
        }
    }
}

void apply_contrast(double value)
{
    auto pixbuf = ImageProcessor::get_instance().get_pixbuf();

    if (!pixbuf_is_valid(pixbuf))
        return;

    int height = pixbuf->get_height();
    int width = pixbuf->get_width();
    int rowstride = pixbuf->get_rowstride();
    int n_channels = pixbuf->get_n_channels();
    guchar *pixels = pixbuf->get_pixels();

#pragma omp parallel for num_threads(4) collapse(2)

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            guchar *pixel = &pixels[y * rowstride + x * n_channels];
            float factor = (259 * (value + 255)) / (255 * (259 - value));

            for (int k = 0; k < n_channels; k++)
                pixel[k] = CLAMP(factor * (pixel[k] - 128) + 128, 0, 255);
        }
    }
}