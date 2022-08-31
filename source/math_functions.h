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

    /**
     * @brief Function for calculating the amount of blacks adjustment for a particular brightness
     * @param brightness The brighness channel of a HSB pixel in range [0.00, 1.00].
     * @param amount The amount of adjustment to apply in range [-1.00, 1.00].
     * @param curveStrength The amount of curvature of the function in range [1.00, ...] (higher number = less effect to blacks).
     * @return The amount of blacks adjustment for the specified brightness
     */
    double adjust_blacks(double brightness, double amount, int curveStrength = 7);

    /**
     * @brief Function for calculating the amount of whites adjustment for a particular brightness
     * @param brightness The brighness channel of a HSB pixel in range [0.00, 1.00].
     * @param amount The amount of adjustment to apply in range [-1.00, 1.00].
     * @param curveStrength The amount of curvature of the function in range [1.00, ...] (higher number = less effect to whites).
     * @return The amount of whites adjustment for the specified brightness
     */
    double adjust_whites(double brightness, double amount, int curveStrength = 7);
}

#endif // MATH_FUNCTIONS_H
