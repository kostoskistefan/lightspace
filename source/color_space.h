#ifndef COLOR_SPACE_H
#define COLOR_SPACE_H

#include "types/rgb_pixel.h"
#include "types/hsb_pixel.h"

/**
 * @namespace ColorSpace
 * @brief Namespace containing methods for converting between color spaces.
 */
namespace ColorSpace
{
    /**
     * @brief Convert an RGB pixel to an HSB pixel.
     * @param[in] rgb The RGB pixel to convert.
     * @param[out] hsb The HSB pixel to store the result in.
     */
    void rgb_to_hsb(RgbPixel &rgb, HsbPixel &hsb);

    /**
     * @brief Convert an HSB pixel to an RGB pixel.
     * @param[in] hsb The HSB pixel to convert.
     * @param[out] rgb The RGB pixel to store the result in.
     */
    void hsb_to_rgb(HsbPixel &hsb, RgbPixel &rgb);
}

#endif // COLOR_SPACE_H