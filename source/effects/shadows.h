#ifndef SHADOWS_H
#define SHADOWS_H

#include "../types/image.h"

/**
 * @namespace Shadows
 * @brief Add shadow adjustment effect to an image.
 */
namespace Shadows
{
    /**
     * @brief Apply shadow adjustment to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of shadow adjustment to apply in range [-1, 1].
     */
    void apply(Image &image, double amount);
}

#endif // SHADOWS_H
