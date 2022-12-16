#ifndef EFFECTS_H
#define EFFECTS_H

#include "../types/effect.h"
#include <vector>

#include "tint.h"
#include "contrast.h"
#include "exposure.h"
#include "saturation.h"
#include "brightness.h"
#include "temperature.h"
#include "shadows.h"
#include "highlights.h"

/**
 * @namespace Effects
 */
namespace Effects
{
    /**
     * @brief Apply effects to an image
     * @param image The image to which the effects will be applied
     * @param effects A list of effects to be applied to the image
     */
    void apply(Image &image, std::vector<effect_t> effects);
}

#endif // EFFECTS_H
