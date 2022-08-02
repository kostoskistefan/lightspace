#include "app_actions.h"
#include "image_dialog.h"
#include "image_processor.h"

ImageDialog *dialog;

void create_action_map(Gtk::Application *app)
{
    app->add_action("open_image", [=] {
        dialog = new ImageDialog(
            app->get_active_window(),
            "Open Image");
            
        dialog->open_image();
    });

    app->add_action("apply_effects", [=] {
        ImageProcessor::get_instance().apply_effects();
    });
}