#ifndef HIGHLIGHTS_H
#define HIGHLIGHTS_H

#include "effect_interface.h"
#include "../types/image.h"

/**
 * @class Highlights
 * @brief Add highlight adjustment effect to an image.
 */
class Highlights : public EffectInterface<Highlights>
{
public:
    /**
     * @brief The name of the class mapped from the effect parser
    */
    static inline const std::string effectIdentifier = "highlights";
    
    /**
     * @brief Create unique instance of this class.
     * @return Unique pointer to this class.
     */
    static std::unique_ptr<Effect> create();

    /**
     * @brief Apply highlight adjustment to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of highlight adjustment to apply in range [-100, 100].
     */
    void apply(Image &image, double amount) override;
};

#endif // HIGHLIGHTS_H
