#ifndef WHITES_H
#define WHITES_H

#include "effect_interface.h"
#include "../types/image.h"

/**
 * @class Whites
 * @brief Add whites adjustment effect to an image.
 */
class Whites : public EffectInterface<Whites>
{
public:
    /**
     * @brief The name of the class mapped from the effect parser
    */
    static inline const std::string effectIdentifier = "whites";
    
    /**
     * @brief Create unique instance of this class.
     * @return Unique pointer to this class.
     */
    static std::unique_ptr<Effect> create();

    /**
     * @brief Apply whites adjustment to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of whites adjustment to apply in range [-100, 100].
     */
    void apply(Image &image, double amount) override;
};

#endif // WHITES_H
