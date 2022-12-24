#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "../types/image.h"
#include "effect_interface.h"

/**
 * @class Temperature
 * @brief Add temperature effect to an image.
 */
class Temperature : public EffectInterface<Temperature>
{
public:
    /**
     * @brief The name of the class mapped from the effect parser
    */
    static inline const std::string effectIdentifier = "temperature";
    
    /**
     * @brief Create unique instance of this class.
     * @return Unique pointer to this class.
     */
    static std::unique_ptr<Effect> create();

    /**
     * @brief Apply temperature to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of temperature to apply in range [-100, 100].
     */
    void apply(Image &image, double amount) override;
};

#endif // TEMPERATURE_H