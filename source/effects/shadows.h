#ifndef SHADOWS_H
#define SHADOWS_H

#include "../types/image.h"
#include "effect_interface.h"

/**
 * @class Shadows
 * @brief Add shadow adjustment effect to an image.
 */
class Shadows : public EffectInterface<Shadows>
{
public:
    /**
     * @brief The name of the class mapped from the effect parser
    */
    static inline const std::string effectIdentifier = "shadows";
    
    /**
     * @brief Create unique instance of this class.
     * @return Unique pointer to this class.
     */
    static std::unique_ptr<Effect> create();

    /**
     * @brief Apply shadow adjustment to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of shadow adjustment to apply in range [-100, 100].
     */
    void apply(Image &image, double amount) override;
};

#endif // SHADOWS_H
