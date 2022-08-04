#ifndef UI_BUILDER_H
#define UI_BUILDER_H

#include <gtkmm.h>

class UIBuilder
{
public:
    static UIBuilder &get_instance();

    template <typename T>
    T *get_widget_from_id(const char *id);

private:
    UIBuilder();
    UIBuilder(UIBuilder const &);
    void operator=(UIBuilder const &);
    Glib::RefPtr<Gtk::Builder> builder;
};

#endif
