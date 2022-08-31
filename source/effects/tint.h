#ifndef TINT_H
#define TINT_H

#include "../types/image.h"

/**
 * @namespace Tint
 * @brief Add tint effect to an image.
 */
namespace Tint
{
    /**
     * @brief Apply tint to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of tint to apply in range [-100, 100].
     */
    void apply(Image &image, double amount);
}

#endif // TINT_H