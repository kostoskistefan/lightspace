#include "ui_builder.h"

UIBuilder &UIBuilder::get_instance()
{
    static UIBuilder instance;
    return instance;
}

UIBuilder::UIBuilder()
{
    builder = Gtk::Builder::create_from_resource("/ui/main_window.xml");
}

Gtk::Widget *UIBuilder::get_widget_from_id(const char *id)
{
    return this->builder->get_widget<Gtk::Widget>(id);
}
