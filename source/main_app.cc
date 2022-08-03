#include "main_app.h"
#include "ui_builder.h"
#include "app_actions.h"
#include "image_processor.h"
#include <gtkmm/cssprovider.h>

MainApplication::MainApplication()
    : Gtk::Application(
          "com.github.kostoskistefan.lightspace",
          Gio::Application::Flags::NONE) {}

Glib::RefPtr<MainApplication> MainApplication::create()
{
    return Glib::make_refptr_for_instance<MainApplication>(new MainApplication());
}

void load_css(Gtk::Window *window)
{
    auto provider = Gtk::CssProvider::create();
    provider->load_from_resource("css/style.css");

    window->get_style_context()->add_provider_for_display(
        window->get_display(),
        provider, 
        GTK_STYLE_PROVIDER_PRIORITY_USER);
}

void load_dark_theme()
{
    Gtk::Settings::get_default()->set_property(
        "gtk-application-prefer-dark-theme", 
        true);
}

void MainApplication::on_activate()
{
    window = static_cast<Gtk::Window *>(
        UIBuilder::get_instance().get_widget_from_id("mainWindow"));
    
    load_css(window);
    load_dark_theme();
    
    AppActions::get_instance().initialize(this, window);

    add_window(*window);
    window->maximize();
    window->show();
}

void on_hide_window(Gtk::Window *window)
{
    delete window;
}

