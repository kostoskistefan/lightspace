#ifndef EXPOSURE_H
#define EXPOSURE_H

#include "../types/image.h"
#include "effect_interface.h"

/**
 * @class Exposure
 * @brief Add exposure effect to an image.
 */
class Exposure : public EffectInterface<Exposure>
{
public:
    /**
     * @brief The name of the class mapped from the effect parser
    */
    static inline const std::string effectIdentifier = "exposure";

    /**
     * @brief Create unique instance of this class.
     * @return Unique pointer to this class.
     */
    static std::unique_ptr<Effect> create();

    /**
     * @brief Apply exposure to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of exposure to apply in range [-3, 3].
     */
    void apply(Image &image, double amount) override;
};

#endif // EXPOSURE_H