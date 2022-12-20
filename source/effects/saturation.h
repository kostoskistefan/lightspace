#ifndef SATURATION_H
#define SATURATION_H

#include "../types/image.h"

/**
 * @namespace Saturation
 * @brief Add saturation effect to an image.
 */
namespace Saturation
{
    /**
     * @brief Apply saturation to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of saturation to apply in range [-100, 100].
     */
    void apply(Image &image, double amount);
}

#endif // SATURATION_H
