#include "effect_processor.h"
#include "../effects/effect.h"
#include "../effects/tint.h"

void EffectProcessor::apply(Image &image, std::vector<std::pair<std::string, double>> &effects)
{
    for (auto const &effect : effects)
    {
        auto effectInstance = Effect::instantiate(effect.first);
        
        if (effectInstance)
            effectInstance->apply(image, effect.second);
    }
}
