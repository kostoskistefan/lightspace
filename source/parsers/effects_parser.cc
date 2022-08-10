#include "effects_parser.h"
#include "../utilities.h"

std::vector<effect_t> EffectsParser::parse(std::string text)
{
    std::vector<effect_t> effects;

    for (auto line : Utilities::split(text, '\n'))
    {
        auto tokens = Utilities::split(line, '=');

        if (tokens.size() != 2)
            continue;

        auto name = Utilities::trim(Utilities::lowercase(tokens[0]));
        auto amount = Utilities::trim(Utilities::lowercase(tokens[1]));

        try {
            effects.push_back({ name, std::stod(amount) });
        } 
        
        catch (...) {
            effects.push_back({ name, 0 });
        }
    }

    return effects;
}