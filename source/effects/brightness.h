#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#include "../types/image.h"
#include "effect_interface.h"

/**
 * @class Brightness
 * @brief Add brightness effect to an image.
 */
class Brightness : public EffectInterface<Brightness>
{
public:
    /**
     * @brief The name of the class mapped from the effect parser
    */
    static inline const std::string effectIdentifier = "brightness";
    
    /**
     * @brief Create unique instance of this class.
     * @return Unique pointer to this class.
     */
    static std::unique_ptr<Effect> create();

    /**
     * @brief Apply brightness to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of brightness to apply in range [-100, 100].
     */
    void apply(Image &image, double amount) override;
};

#endif // BRIGHTNESS_H
