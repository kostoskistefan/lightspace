#ifndef EFFECT_H
#define EFFECT_H

#include <string>
#include <unordered_map>
#include "../types/image.h"

class Effect
{
public:
    virtual ~Effect() = default;
    virtual void apply(Image &image, double amount) = 0;
    virtual void DoNotInheritFromEffectDirectlyButFromEffectInterfaceInstead() = 0;

    static std::unique_ptr<Effect> instantiate(std::string const &name);
    static std::unordered_map<std::string, std::function<std::unique_ptr<Effect>()>> &get_registry();
};

#endif // EFFECT_H
