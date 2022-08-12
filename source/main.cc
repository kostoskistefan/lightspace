#include <gtkmm.h>
#include "lightspace_window.h"

static void on_activate(std::shared_ptr<Gtk::Application> &app)
{
    // Get the current window. If there is not one, we will create it.
    static std::unique_ptr<Gtk::Window> window;

    if (!window)
    {
        window = LightspaceWindow::create();
        window->property_application() = app;
        app->add_window(*window);
    }

    // Ask the window manager/compositor to show the window to the user.
    window->show();
}

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create("com.github.kostoskistefan.lightspace");

    app->signal_activate().connect(sigc::bind(&on_activate, app));

    return app->run(argc, argv);
}
