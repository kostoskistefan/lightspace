#include "effect.h"
#include "pixel.h"
#include "utilities.h"
#include "image_data.h"
#include "color_space.h"
#include "image_processor.h"
#include <omp.h>

void apply_temperature(double value)
{
    ImageData data = ImageData::get_pixbuf_image_data(
        ImageProcessor::get_instance().get_pixbuf());

    if (!data.is_valid())
        return;

    #pragma omp parallel for num_threads(4) collapse(2)

    for (int x = 0; x < data.width; x++)
    {
        for (int y = 0; y < data.height; y++)
        {
            pixel_ref_t pixel = &data.pixels[y * data.rowstride + x * data.n_channels];

            *pixel.r = CLAMP(*pixel.r + value, 0, 255);
            *pixel.b = CLAMP(*pixel.b - value, 0, 255);
        }
    }
}

void apply_tint(double value)
{
    ImageData data = ImageData::get_pixbuf_image_data(
        ImageProcessor::get_instance().get_pixbuf());

    if (!data.is_valid())
        return;

    #pragma omp parallel for num_threads(4) collapse(2)

    for (int x = 0; x < data.width; x++)
    {
        for (int y = 0; y < data.height; y++)
        {
            pixel_ref_t pixel = &data.pixels[y * data.rowstride + x * data.n_channels];
            *pixel.g = CLAMP(*pixel.g + value, 0, 255);
        }
    }
}

void apply_exposure(double value)
{
    ImageData data = ImageData::get_pixbuf_image_data(
        ImageProcessor::get_instance().get_pixbuf());

    if (!data.is_valid())
        return;

    double powValue = fastPow(2, value);

    #pragma omp parallel for num_threads(4) collapse(2)

    for (int x = 0; x < data.width; x++)
    {
        for (int y = 0; y < data.height; y++)
        {
            pixel_ref_t pixel = &data.pixels[y * data.rowstride + x * data.n_channels];

            *pixel.r = CLAMP(*pixel.r * powValue, 0, 255);
            *pixel.g = CLAMP(*pixel.g * powValue, 0, 255);
            *pixel.b = CLAMP(*pixel.b * powValue, 0, 255);
        }
    }
}

void apply_contrast(double value)
{
    ImageData data = ImageData::get_pixbuf_image_data(
        ImageProcessor::get_instance().get_pixbuf());

    if (!data.is_valid())
        return;

    float factor = (259 * (value + 255)) / (255 * (259 - value));

    #pragma omp parallel for num_threads(4) collapse(2)

    for (int x = 0; x < data.width; x++)
    {
        for (int y = 0; y < data.height; y++)
        {
            pixel_ref_t pixel = &data.pixels[y * data.rowstride + x * data.n_channels];

            *pixel.r = CLAMP(factor * (*pixel.r - 128) + 128, 0, 255);
            *pixel.g = CLAMP(factor * (*pixel.g - 128) + 128, 0, 255);
            *pixel.b = CLAMP(factor * (*pixel.b - 128) + 128, 0, 255);
        }
    }
}

void apply_saturation(double value)
{
    ImageData data = ImageData::get_pixbuf_image_data(
        ImageProcessor::get_instance().get_pixbuf());

    if (!data.is_valid())
        return;

    #pragma omp parallel for num_threads(4) collapse(2)

    for (int x = 0; x < data.width; x++)
    {
        for (int y = 0; y < data.height; y++)
        {
            pixel_ref_t pixel = &data.pixels[y * data.rowstride + x * data.n_channels];

            rgb_color_t rgbColor = {*pixel.r, *pixel.g, *pixel.b};

            hsb_color_t hsb = rgb_to_hsb(rgbColor);

            hsb.s = CLAMP(hsb.s * value, 0.0f, 1.0f);

            rgb_color_t saturatedPixel = hsb_to_rgb(hsb);

            *pixel.r = saturatedPixel.r;
            *pixel.g = saturatedPixel.g;
            *pixel.b = saturatedPixel.b;
        }
    }
}

void apply_grayscale(bool value)
{
    if (!value)
        return;

    ImageData data = ImageData::get_pixbuf_image_data(
        ImageProcessor::get_instance().get_pixbuf());

    if (!data.is_valid())
        return;

    for (int x = 0; x < data.width; x++)
    {
        for (int y = 0; y < data.height; y++)
        {
            pixel_ref_t pixel = &data.pixels[y * data.rowstride + x * data.n_channels];

            guint8 intensity = (*pixel.r + *pixel.g + *pixel.b) / 3;

            pixel = intensity;
        }
    }
}
