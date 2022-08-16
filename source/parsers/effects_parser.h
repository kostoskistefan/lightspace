#ifndef EFFECTS_PARSER_H
#define EFFECTS_PARSER_H

#include <vector>
#include "../types/effect.h"

/**
 * @namespace EffectsParser
 * @brief Create a list of effect objects from user entered text
 */
namespace EffectsParser
{
    /**
     * @brief Parse the user entered effects from the text view.
     * @param text The text to parse.
     * @return A list of the parsed effects.
     */
    std::vector<effect_t> parse(std::string text);
}

#endif // EFFECTS_PARSER_H