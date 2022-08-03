#include "effect.h"
#include "pixel.h"
#include "utilities.h"
#include "image_data.h"
#include "color_space.h"
#include <omp.h>

void apply_temperature(double value)
{
    ImageData data = ImageData::get_pixbuf_image_data(
        ImageProcessor::get_instance().get_pixbuf());

    if (!data.is_valid())
        return;

    double clampedValue = CLAMP(value, -100, 100);

#pragma omp parallel for num_threads(4) collapse(2)

    for (int x = 0; x < data.width; x++)
    {
        for (int y = 0; y < data.height; y++)
        {
            Pixel pixel = &data.pixels[y * data.rowstride + x * data.n_channels];

            *pixel.r = CLAMP(*pixel.r + clampedValue, 0, 255);
            *pixel.b = CLAMP(*pixel.b - clampedValue, 0, 255);
        }
    }
}

void apply_tint(double value)
{
    ImageData data = ImageData::get_pixbuf_image_data(
        ImageProcessor::get_instance().get_pixbuf());

    if (!data.is_valid())
        return;

    double clampedValue = CLAMP(value, -100, 100);

#pragma omp parallel for num_threads(4) collapse(2)

    for (int x = 0; x < data.width; x++)
    {
        for (int y = 0; y < data.height; y++)
        {
            Pixel pixel = &data.pixels[y * data.rowstride + x * data.n_channels];
            *pixel.g = CLAMP(*pixel.g + clampedValue, 0, 255);
        }
    }
}

void apply_exposure(double value)
{
    ImageData data = ImageData::get_pixbuf_image_data(
        ImageProcessor::get_instance().get_pixbuf());

    if (!data.is_valid())
        return;

    double clampedValue = CLAMP(value, -2.0f, 2.0f);
    double powValue = fastPow(2, clampedValue);

#pragma omp parallel for num_threads(4) collapse(2)

    for (int x = 0; x < data.width; x++)
    {
        for (int y = 0; y < data.height; y++)
        {
            Pixel pixel = &data.pixels[y * data.rowstride + x * data.n_channels];

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

    float factor = (259 * (CLAMP(value, -100, 100) + 255)) / (255 * (259 - value));

#pragma omp parallel for num_threads(4) collapse(2)

    for (int x = 0; x < data.width; x++)
    {
        for (int y = 0; y < data.height; y++)
        {
            Pixel pixel = &data.pixels[y * data.rowstride + x * data.n_channels];

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
    
    double clampedValue =  CLAMP(value, 0, 2);

#pragma omp parallel for num_threads(4) collapse(2)

    for (int x = 0; x < data.width; x++)
    {
        for (int y = 0; y < data.height; y++)
        {
            Pixel pixel = &data.pixels[y * data.rowstride + x * data.n_channels];

            RgbColor rgbColor = {*pixel.r, *pixel.g, *pixel.b};

            HsvColor hsv = rgb_to_hsv(rgbColor);

            hsv.s = CLAMP(hsv.s * clampedValue, 0.0f, 1.0f);

            RgbColor saturatedPixel = hsv_to_rgb(hsv);

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
            Pixel pixel = &data.pixels[y * data.rowstride + x * data.n_channels];

            guint8 intensity = (*pixel.r + *pixel.g + *pixel.b) / 3;

            pixel = CLAMP(intensity, 0, 255);
        }
    }
}
