#ifndef EXPOSURE_H
#define EXPOSURE_H

#include "../types/image.h"

/**
 * @namespace Exposure
 * @brief Add exposure effect to an image.
 */
namespace Exposure
{
    /**
     * @brief Apply exposure to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of exposure to apply in range [-3, 3].
     */
    void apply(Image &image, double amount);
}

#endif // EXPOSURE_H