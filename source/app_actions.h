#ifndef APP_ACTIONS_H
#define APP_ACTIONS_H

#include <gtkmm.h>
#include "image_dialog.h"

class AppActions
{
public:
    static AppActions &get_instance();
    void create_action_map(Gtk::Window *appWindow);

private:
    AppActions();
    AppActions(AppActions const &);
    void operator=(AppActions const &);

    ImageDialog *dialog;
};

#endif // APP_ACTIONS_H