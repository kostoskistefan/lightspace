#include "app_actions.h"
#include "image_dialog.h"
#include "image_processor.h"

AppActions &AppActions::get_instance()
{
    static AppActions instance;
    return instance;
}

AppActions::AppActions()
{
    this->dialog = new ImageDialog();
}

bool AppActions::on_key_pressed(guint keyval, guint, Gdk::ModifierType state)
{
    switch (keyval)
    {
    case GDK_KEY_Tab:
        ImageProcessor::get_instance().toggle_dual_view();
        break;
    case GDK_KEY_backslash:
        ImageProcessor::get_instance().toggle_before_after();
        break;
    }

    return true;
}

void AppActions::initialize_keyboard_handler(Gtk::Application *app, Gtk::Window *mainWindow)
{
    auto controller = Gtk::EventControllerKey::create();

    controller->signal_key_pressed().connect(
        sigc::mem_fun(*this, &AppActions::on_key_pressed), false);

    mainWindow->add_controller(controller);
}

void AppActions::create_action_map(Gtk::Application *app, Gtk::Window *mainWindow)
{
    app->add_action("open_image", [=]
                    {
        this->dialog->set_parent(mainWindow);
        this->dialog->set_title("Open Image");
        this->dialog->set_action(Gtk::FileChooser::Action::OPEN);
            
        this->dialog->open_image(); });

    app->add_action("export_image", [=]
                    {
        this->dialog->set_parent(mainWindow);
        this->dialog->set_title("Export Image");
        this->dialog->set_action(Gtk::FileChooser::Action::SAVE);
            
        this->dialog->export_image(); });

    app->add_action("apply_effects", [=]
                    { ImageProcessor::get_instance().apply_effects(); });

    app->add_action("toggle_dual_view", [=]
                    { ImageProcessor::get_instance().toggle_dual_view(); });
    
    app->add_action("toggle_before_after", [=]
                    { ImageProcessor::get_instance().toggle_before_after(); });
}

void AppActions::initialize(Gtk::Application *app, Gtk::Window *mainWindow)
{
    create_action_map(app, mainWindow);
    initialize_keyboard_handler(app, mainWindow);
}