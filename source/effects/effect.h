#ifndef EFFECT_H
#define EFFECT_H

#include <string>
#include <unordered_map>
#include "../types/image.h"

/**
 * @class Effect
 * @brief A base class for all effects
 */
class Effect
{
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~Effect() = default;

    /**
     * @brief Function that applies a certain effect to an Image
     * @param image The image to add the effect to.
     * @param amount The amount of blacks adjustment to apply in range [-100, 100].
     */
    virtual void apply(Image &image, double amount) = 0;

    /**
     * @brief A pure virtual function that doesn't allow inheritance directly from this class,
     * instead, it requires the use of the EffectInterface class
     */
    virtual void DoNotInheritFromEffectDirectlyButFromEffectInterfaceInstead() = 0;

    /**
     * @brief Instantiates an effect class from a mapped name
     * @param name The name of the effect that needs to be instantiated
     * @return A pointer to the effect class instance
     */
    static std::unique_ptr<Effect> instantiate(std::string const &name);

    /**
     * @brief Get the registrar containing the effect class mappings
     * @return A map containing all registered effects
     */
    static std::unordered_map<std::string, std::function<std::unique_ptr<Effect>()>> &get_registry();
};

#endif // EFFECT_H
