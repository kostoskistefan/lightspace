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

template <typename T>
T *UIBuilder::get_widget_from_id(const char *id)
{
    return this->builder->get_widget<T>(id);
}
