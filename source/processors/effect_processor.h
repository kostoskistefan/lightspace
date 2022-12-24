#ifndef EFFECT_PROCESSOR_H
#define EFFECT_PROCESSOR_H

#include <vector>
#include "../types/image.h"

namespace EffectProcessor
{
    void apply(Image &image, std::vector<std::pair<std::string, double>> &effects);
}

#endif // EFFECT_PROCESSOR_H