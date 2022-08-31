#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "../types/image.h"

/**
 * @namespace Temperature
 * @brief Add temperature effect to an image.
 */
namespace Temperature
{
    /**
     * @brief Apply temperature to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of temperature to apply in range [-100, 100].
     */
    void apply(Image &image, double amount);
}

#endif // TEMPERATURE_H