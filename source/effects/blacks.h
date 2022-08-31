#ifndef BLACKS_H
#define BLACKS_H

#include "../types/image.h"

/**
 * @namespace Blacks
 * @brief Adjust blacks of an image.
 */
namespace Blacks
{
    /**
     * @brief Apply blacks adjustment to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of adjustment to apply in range [0.00, 1.00].
     */
    void apply(Image &image, double amount);
}

#endif // BLACKS_H