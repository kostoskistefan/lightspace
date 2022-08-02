#ifndef MAIN_APP_H
#define MAIN_APP_H

#include <gtkmm.h>

class MainApplication : public Gtk::Application
{
protected:
    MainApplication();

public:
    static Glib::RefPtr<MainApplication> create();

protected:
    void on_activate() override;

private:
    Gtk::Window *window;
    void on_hide_window(Gtk::Window *window);
};

#endif // MAIN_APP_H
