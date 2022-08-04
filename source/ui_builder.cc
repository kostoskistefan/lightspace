#include "ui_builder.h"

UIBuilder &UIBuilder::get_instance()
{
    static UIBuilder instance;
    return instance;
}

UIBuilder::UIBuilder()
{
    builder = Gtk::Builder::create_from_resource("/ui/app_window.xml");
}
