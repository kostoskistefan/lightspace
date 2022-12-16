#include "effects.h"

void Effects::apply(Image &image, std::vector<effect_t> effects)
{
    for (auto effect : effects)
    {
        if (effect.name == "brightness")
            Brightness::apply(image, effect.amount);

        else if (effect.name == "exposure")
            Exposure::apply(image, effect.amount);

        else if (effect.name == "contrast")
            Contrast::apply(image, effect.amount);

        else if (effect.name == "saturation")
            Saturation::apply(image, effect.amount);

        else if (effect.name == "temperature")
            Temperature::apply(image, effect.amount);

        else if (effect.name == "tint")
            Tint::apply(image, effect.amount);

        else if (effect.name == "shadows")
            Shadows::apply(image, effect.amount);

        else if (effect.name == "highlights")
            Highlights::apply(image, effect.amount);
    }
}
