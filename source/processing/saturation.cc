#include "saturation.h"
#include "../pixel.h"
#include "../color_space.h"
#include "../image_data.h"
#include "../image_processor.h"
#include <omp.h>

void Saturation::normalize(double *amount)
{
    *amount = CLAMP(*amount, 0, 2.0f);
}

void Saturation::apply(double amount)
{
    ImageData data = ImageData::get_pixbuf_image_data(
        ImageProcessor::get_instance().get_pixbuf());

    if (!data.is_valid())
        return;

    Saturation::normalize(&amount);

    #pragma omp parallel for num_threads(4) collapse(2)

    for (int x = 0; x < data.width; x++)
    {
        for (int y = 0; y < data.height; y++)
        {
            pixel_ref_t pixel = &data.pixels[y * data.rowstride + x * data.n_channels];

            rgb_color_t rgbColor = {*pixel.r, *pixel.g, *pixel.b};

            hsb_color_t hsb = rgb_to_hsb(rgbColor);

            hsb.s = CLAMP(hsb.s * amount, 0.0f, 1.0f);

            rgb_color_t saturatedPixel = hsb_to_rgb(hsb);

            *pixel.r = saturatedPixel.r;
            *pixel.g = saturatedPixel.g;
            *pixel.b = saturatedPixel.b;
        }
    }
}