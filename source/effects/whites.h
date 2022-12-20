#ifndef WHITES_H
#define WHITES_H

#include "../types/image.h"

/**
 * @namespace Whites 
 * @brief Add whites adjustment effect to an image.
 */
namespace Whites 
{
    /**
     * @brief Apply whites adjustment to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of whites adjustment to apply in range [-100, 100].
     */
    void apply(Image &image, double amount);
}

#endif // WHITES_H
