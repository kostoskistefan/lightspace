#include "effects_parser.h"
#include "../utilities.h"

std::vector<std::pair<std::string, double>> EffectsParser::parse(std::string text)
{
    std::vector<std::pair<std::string, double>> effects;

    for (auto line : Utilities::split(text, '\n'))
    {
        auto tokens = Utilities::split(line, '=');

        if (tokens.size() != 2)
            continue;

        auto name = Utilities::trim(Utilities::lowercase(tokens[0]));
        auto amount = Utilities::trim(Utilities::lowercase(tokens[1]));

        try {
            effects.emplace_back(name, std::stod(amount));
        } 
        
        catch (...) {}
    }

    return effects;
}