#ifndef BLACKS_H
#define BLACKS_H

#include "../types/image.h"
#include "effect_interface.h"

/**
 * @class Blacks 
 * @brief Add blacks adjustment effect to an image.
 */
class Blacks : public EffectInterface<Blacks>
{
public:
    /**
     * @brief The name of the class mapped from the effect parser
    */
    static inline const std::string effectIdentifier = "blacks";

    /**
     * @brief Create unique instance of this class.
     * @return Unique pointer to this class.
     */
    static std::unique_ptr<Effect> create();

    /**
     * @brief Apply blacks adjustment to the image.
     * @param image The image to add the effect to.
     * @param amount The amount of blacks adjustment to apply in range [-100, 100].
     */
    void apply(Image &image, double amount) override;
};

#endif // BLACKS_H
