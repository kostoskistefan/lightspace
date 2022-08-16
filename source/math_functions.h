#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

#include "types/image.h"
#include "types/kernel.h"

/**
 * @namespace MathFunctions
 * @brief A namespace containing various math 
 * functions for image processing.
 */
namespace MathFunctions
{
    /**
     * @brief Apply a convolution kernel to an image.
     * @param image The image to apply the convolution kernel to.
     * @param kernel The convolution kernel to be applied. 
     * NOTE: The kernel must be odd sized and flipped horizontally and vertically.
     */
    void convolve(Image &image, Kernel &kernel);
}

#endif // MATH_FUNCTIONS_H
