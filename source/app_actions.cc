#include "app_actions.h"
#include "image_dialog.h"
#include "processing/image_processor.h"
#include "gui.h"

AppActions &AppActions::get_instance()
{
    static AppActions instance;
    return instance;
}

AppActions::AppActions() {}

static void open_image_callback()
{
    auto dialog = new ImageDialog(GUI::get_instance().get_main_window());
    dialog->set_title("Open Image");
    dialog->set_action(Gtk::FileChooser::Action::OPEN);
    dialog->open_image();
}

static void export_image_callback()
{
    auto dialog = new ImageDialog(GUI::get_instance().get_main_window());
    dialog->set_title("Export Image");
    dialog->set_action(Gtk::FileChooser::Action::SAVE);
    dialog->export_image();
}

static void apply_effects_callback()
{
    ImageProcessor::get_instance().apply_effects();
}

static void toggle_dial_view_callback()
{
    GUI::get_instance().toggle_dual_view();
}

static void toggle_before_after_callback()
{
    GUI::get_instance().toggle_before_after();
}

void AppActions::create_action_map()
{
    auto app = static_cast<Gtk::Application *>(Gtk::Application::get_default().get());

    app->add_action("open_image", sigc::ptr_fun(open_image_callback));
    app->add_action("export_image", sigc::ptr_fun(export_image_callback));
    app->add_action("apply_effects", sigc::ptr_fun(apply_effects_callback));
    app->add_action("toggle_dual_view", sigc::ptr_fun(toggle_dial_view_callback));
    app->add_action("toggle_before_after", sigc::ptr_fun(toggle_before_after_callback));
}