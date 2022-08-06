#include "effect.h"
#include "tint.h"
#include "temperature.h"
#include "exposure.h"
#include "contrast.h"
#include "saturation.h"
#include "grayscale.h"
#include "../utilities.h"
#include "../gui.h"

void Effect::apply(Glib::ustring name, Glib::ustring amount)
{
    if (name == "temperature")
        Temperature::apply(string_to_double(amount));

    else if (name == "tint")
        Tint::apply(string_to_double(amount));

    else if (name == "exposure")
        Exposure::apply(string_to_double(amount));

    else if (name == "contrast")
        Contrast::apply(string_to_double(amount));

    else if (name == "saturation")
        Saturation::apply(string_to_double(amount));

    else if (name == "grayscale")
        Grayscale::apply(string_to_bool(amount));

    GUI::get_instance().redraw_picture();
}