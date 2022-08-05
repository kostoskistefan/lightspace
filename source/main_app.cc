#include "main_app.h"
#include "gui.h"
#include "app_actions.h"
#include "signal_handler.h"
#include "image_processor.h"
#include <gtkmm/cssprovider.h>

MainApplication::MainApplication()
    : Gtk::Application("com.github.kostoskistefan.lightspace") {}

Glib::RefPtr<MainApplication> MainApplication::create()
{
    return Glib::make_refptr_for_instance<MainApplication>(new MainApplication());
}

void MainApplication::on_activate()
{
    window = GUI::get_instance().get_main_window();

    AppActions::get_instance().create_action_map();

    add_window(*window);
    window->maximize();
    window->show();

    SignalHandler::get_instance();
    GUI::get_instance().set_initial_widget_sensitivity();
}

void on_hide_window(Gtk::Window *window)
{
    delete window;
}
