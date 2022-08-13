#ifndef EFFECTS_PARSER_H
#define EFFECTS_PARSER_H

#include <vector>
#include "../types/effect.h"

namespace EffectsParser
{
    std::vector<effect_t> parse(std::string text);
}

#endif // EFFECTS_PARSER_H