#ifndef UI_BUILDER_H
#define UI_BUILDER_H

#include <gtkmm.h>

class UIBuilder
{
public:
    static UIBuilder &get_instance();

    template <typename T>
    T *get_widget(const char *id)
    {
        // Must be implemented in the header file, since c++ doesn't support
        // template methods to be separated in the header file and the cpp file.
        return this->builder->get_widget<T>(id);
    }

private:
    UIBuilder();
    UIBuilder(UIBuilder const &);
    void operator=(UIBuilder const &);
    Glib::RefPtr<Gtk::Builder> builder;
};

#endif
