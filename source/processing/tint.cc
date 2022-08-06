#include "tint.h"
#include "../pixel.h"
#include "../image_data.h"
#include "../image_processor.h"
#include <omp.h>

void Tint::normalize(double *amount)
{
    *amount = CLAMP(*amount, -100, 100);
}

void Tint::apply(double amount)
{
    ImageData data = ImageData::get_pixbuf_image_data(
        ImageProcessor::get_instance().get_pixbuf());

    if (!data.is_valid())
        return;

    Tint::normalize(&amount);

    #pragma omp parallel for num_threads(4) collapse(2)

    for (int x = 0; x < data.width; x++)
    {
        for (int y = 0; y < data.height; y++)
        {
            pixel_ref_t pixel = &data.pixels[y * data.rowstride + x * data.n_channels];

            *pixel.g = CLAMP(*pixel.g + amount, 0, 255);
        }
    }
}