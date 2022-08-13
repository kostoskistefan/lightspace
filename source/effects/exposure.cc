#include "exposure.h"
#include <cmath>

void Exposure::apply(Image &image, double amount)
{
    if (!image.is_valid() || amount == 0)
        return;

    double value = std::pow(2, amount);

    for (int y = 0; y < image.height; y++)
        for (int x = 0; x < image.width; x++)
            image.at(x, y) *= value;
}