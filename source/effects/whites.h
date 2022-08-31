#ifndef WHITES_H
#define WHITES_H

#include "../types/image.h"

/**
 * @namespace Whites
 * @brief Adjust whites of an image.
 */
namespace Whites
{
    /**
     * @brief Apply whites adjustment to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of adjustment to apply in range [0.00, 1.00].
     */
    void apply(Image &image, double amount);
}

#endif // WHITES_H