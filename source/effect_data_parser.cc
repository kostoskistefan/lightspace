#include "effect_data_parser.h"
#include "gui.h"
#include "utilities.h"
#include "processing/effect.h"

void parse_effect_data()
{
    auto text = GUI::get_instance()
                    .get_effects_text_view()
                    ->get_buffer()
                    ->get_text();

    g_return_if_fail(!text.empty());

    for (auto line : split(text, '\n'))
    {
        auto tokens = split(line, '=');

        if (tokens.size() != 2)
            continue;

        auto name = tokens[0].lowercase();
        auto amount = tokens[1].lowercase();

        trim(name);
        trim(amount);

        Effect::apply(name, amount);
    }
}