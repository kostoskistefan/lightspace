#include "exposure.h"
#include "../pixel.h"
#include "../utilities.h"
#include "../image_data.h"
#include "image_processor.h"
#include <omp.h>

void Exposure::normalize(double *amount)
{
    *amount = CLAMP(*amount, -2.0f, 2.0f);
}

void Exposure::apply(double amount)
{
    ImageData data = ImageData::get_pixbuf_image_data(
        ImageProcessor::get_instance().get_pixbuf());

    if (!data.is_valid())
        return;

    Exposure::normalize(&amount);
    
    double powValue = fastPow(2, amount);

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