#ifndef HIGHLIGHTS_H
#define HIGHLIGHTS_H

#include "../types/image.h"

/**
 * @namespace Highlights 
 * @brief Add highlight adjustment effect to an image.
 */
namespace Highlights
{
    /**
     * @brief Apply highlight adjustment to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of highlight adjustment to apply in range [-1, 1].
     */
    void apply(Image &image, double amount);
}

#endif // HIGHLIGHTS_H
