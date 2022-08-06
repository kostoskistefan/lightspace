#include "contrast.h"
#include "../pixel.h"
#include "../image_data.h"
#include "image_processor.h"
#include <omp.h>

void Contrast::normalize(double *amount)
{
    *amount = CLAMP(*amount, -100, 100);
}

void Contrast::apply(double amount)
{
    ImageData data = ImageData::get_pixbuf_image_data(
        ImageProcessor::get_instance().get_pixbuf());

    if (!data.is_valid())
        return;

    Contrast::normalize(&amount);
    
    float factor = (259 * (amount + 255)) / (255 * (259 - amount));

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