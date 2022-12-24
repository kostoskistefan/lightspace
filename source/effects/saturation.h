#ifndef SATURATION_H
#define SATURATION_H

#include "effect_interface.h"
#include "../types/image.h"

/**
 * @class Saturation
 * @brief Add saturation effect to an image.
 */
class Saturation : public EffectInterface<Saturation>
{
public:
    /**
     * @brief The name of the class mapped from the effect parser
    */
    static inline const std::string effectIdentifier = "saturation";
    
    /**
     * @brief Create unique instance of this class.
     * @return Unique pointer to this class.
     */
    static std::unique_ptr<Effect> create();

    /**
     * @brief Apply saturation to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of saturation to apply in range [-100, 100].
     */
    void apply(Image &image, double amount) override;
};

#endif // SATURATION_H
