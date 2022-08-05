#include "app_actions.h"
#include "image_dialog.h"
#include "image_processor.h"
#include "gui.h"

AppActions &AppActions::get_instance()
{
    static AppActions instance;
    return instance;
}

AppActions::AppActions()
{
    this->dialog = new ImageDialog();
}

void AppActions::create_action_map()
{
    auto app = static_cast<Gtk::Application *>(Gtk::Application::get_default().get());
    auto window = GUI::get_instance().get_main_window();
    
    app->add_action("open_image", [=]
                    {
        this->dialog->set_parent(window);
        this->dialog->set_title("Open Image");
        this->dialog->set_action(Gtk::FileChooser::Action::OPEN);
            
        this->dialog->open_image(); });

    app->add_action("export_image", [=]
                    {
        this->dialog->set_parent(window);
        this->dialog->set_title("Export Image");
        this->dialog->set_action(Gtk::FileChooser::Action::SAVE);
            
        this->dialog->export_image(); });

    app->add_action("apply_effects", [=]
                    { ImageProcessor::get_instance().apply_effects(); });

    app->add_action("toggle_dual_view", [=]
                    { GUI::get_instance().toggle_dual_view(); });
    
    app->add_action("toggle_before_after", [=]
                    { GUI::get_instance().toggle_before_after(); });
}