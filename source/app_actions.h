#ifndef APP_ACTIONS_H
#define APP_ACTIONS_H

#include <gtkmm.h>
#include "image_dialog.h"

class AppActions
{
public:
    static AppActions &get_instance();
    void initialize(Gtk::Application *app, Gtk::Window *mainWindow);

private:
    AppActions();
    AppActions(AppActions const &);
    void operator=(AppActions const &);

    ImageDialog *dialog;
    void create_action_map(Gtk::Application *app, Gtk::Window *mainWindow);
    bool on_key_pressed(guint keyval, guint, Gdk::ModifierType state);
    void initialize_keyboard_handler(Gtk::Application *app, Gtk::Window *mainWindow);
};

#endif // APP_ACTIONS_H