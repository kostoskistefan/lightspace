#include "brightness.h"

#ifdef _OPENMP
#include <omp.h>
#endif

void Brightness::apply(Image &image, double amount)
{
    if (!image.is_valid() || amount == 0)
        return;

#ifdef _OPENMP
#pragma omp parallel for collapse(2)
#endif

    for (int y = 0; y < image.height; y++)
        for (int x = 0; x < image.width; x++)
            image.at(x, y) += amount;
}

std::unique_ptr<Effect> Brightness::create()
{
    return std::make_unique<Brightness>();
}
