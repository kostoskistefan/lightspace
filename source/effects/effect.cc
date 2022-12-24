#include "effect.h"

std::unordered_map<std::string, std::function<std::unique_ptr<Effect>()>> &Effect::get_registry()
{
    static std::unordered_map<std::string, std::function<std::unique_ptr<Effect>()>> registry;
    
    return registry;
}

std::unique_ptr<Effect> Effect::instantiate(std::string const &name)
{
    auto it = get_registry().find(name);

    if (it == get_registry().end())
        return nullptr;

    return it->second();
}