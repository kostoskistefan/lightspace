#ifndef CONTRAST_H
#define CONTRAST_H

#include "../types/image.h"
#include "effect_interface.h"

/**
 * @class Contrast
 * @brief Add contrast effect to an image.
 */
class Contrast : public EffectInterface<Contrast>
{
public:
    /**
     * @brief The name of the class mapped from the effect parser
    */
    static inline const std::string effectIdentifier = "contrast";
    
    /**
     * @brief Create unique instance of this class.
     * @return Unique pointer to this class.
     */
    static std::unique_ptr<Effect> create();

    /**
     * @brief Apply contrast to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of contrast to apply in range [-100, 100].
     */
    void apply(Image &image, double amount) override;
};

#endif // CONTRAST_H