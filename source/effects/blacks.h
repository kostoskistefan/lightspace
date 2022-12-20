#ifndef BLACKS_H
#define BLACKS_H

#include "../types/image.h"

/**
 * @namespace Blacks 
 * @brief Add blacks adjustment effect to an image.
 */
namespace Blacks
{
    /**
     * @brief Apply blacks adjustment to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of blacks adjustment to apply in range [-100, 100].
     */
    void apply(Image &image, double amount);
}

#endif // BLACKS_H
