#include "effect_data_parser.h"
#include "ui_builder.h"
#include "effect.h"
#include "utilities.h"

void parse_effect_data()
{
    auto textView = UIBuilder::get_instance()
                        .get_widget<Gtk::TextView>("textView");

    auto text = textView->get_buffer()->get_text();

    g_return_if_fail(!text.empty());

    for (auto line : split(text, '\n'))
    {
        auto tokens = split(line, '=');

        if (tokens.size() != 2)
            continue;

        auto name = tokens[0].lowercase();
        auto value = tokens[1].lowercase();

        trim(name);
        trim(value);

        if (name == "temperature")
            apply_temperature(CLAMP(string_to_double(value), -100, 100));

        else if (name == "tint")
            apply_tint(CLAMP(string_to_double(value), -100, 100));

        else if (name == "exposure")
            apply_exposure(CLAMP(string_to_double(value), -2.0f, 2.0f));

        else if (name == "contrast")
            apply_contrast(CLAMP(string_to_double(value), -100, 100));

        else if (name == "saturation")
            apply_saturation(CLAMP(string_to_double(value), 0, 2.0f));

        else if (name == "grayscale")
            apply_grayscale(string_to_bool(value));
    }
}