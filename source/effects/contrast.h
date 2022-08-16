#ifndef CONTRAST_H
#define CONTRAST_H

#include "../types/image.h"

/**
 * @namespace Contrast
 * @brief Add contrast effect to an image.
 */
namespace Contrast
{
    /**
     * @brief Apply contrast to the image.
     * @param image The image to add the effect to.
     * @param contrast The amount of contrast to apply in range [-100, 100].
     */
    void apply(Image &image, double amount);
}

#endif // CONTRAST_H