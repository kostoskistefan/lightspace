#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#include "../types/image.h"

/**
 * @namespace Brightness
 * @brief Add brightness effect to an image.
 */
namespace Brightness
{
    /**
     * @brief Apply brightness to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of brightness to apply in range [-100, 100].
     */
    void apply(Image &image, double amount);
}

#endif // BRIGHTNESS_H