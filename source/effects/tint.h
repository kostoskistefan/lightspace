#ifndef TINT_H
#define TINT_H

#include "../types/image.h"
#include "effect_interface.h"

/**
 * @class Tint
 * @brief Add tint effect to an image.
 */
class Tint : public EffectInterface<Tint>
{
public:
    /**
     * @brief The name of the class mapped from the effect parser
    */
    static inline const std::string effectIdentifier = "tint";
    
    /**
     * @brief Create unique instance of this class.
     */
    static std::unique_ptr<Effect> create();

    /**
     * @brief Apply tint to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of tint to apply in range [-100, 100].
     */
    void apply(Image &image, double amount) override;
};

#endif // TINT_H