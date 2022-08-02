#include "effect_data_parser.h"
#include "ui_builder.h"
#include "effect.h"
#include "utilities.h"

void parse_effect_data()
{
    auto textView = static_cast<Gtk::TextView *>(
        UIBuilder::get_instance().get_widget_from_id("textView")
    );

    auto text = textView->get_buffer()->get_text();

    for (auto line : split(text, '\n'))
    {
        auto tokens = split(line, '=');

        if (tokens.size() != 2) 
            continue;

        auto effectName = tokens[0];
        auto effectValue = tokens[1];

        trim(effectName);
        trim(effectValue);

        if (effectName.lowercase() == "temperature")
            apply_temperature(string_to_double(effectValue));
        
        else if (effectName.lowercase() == "tint")
            apply_tint(string_to_double(effectValue));
        
        else if (effectName.lowercase() == "exposure")
            apply_exposure(string_to_double(effectValue));
        
        else if (effectName.lowercase() == "contrast")
            apply_contrast(string_to_double(effectValue));
    }
}