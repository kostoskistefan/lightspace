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

void AppActions::create_action_map(Gtk::Window *appWindow)
{
    auto app = static_cast<Gtk::Application *>(Gtk::Application::get_default().get());
    
    app->add_action("open_image", [=]
                    {
        this->dialog->set_parent(appWindow);
        this->dialog->set_title("Open Image");
        this->dialog->set_action(Gtk::FileChooser::Action::OPEN);
            
        this->dialog->open_image(); });

    app->add_action("export_image", [=]
                    {
        this->dialog->set_parent(appWindow);
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