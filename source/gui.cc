#include "gui.h"
#include "ui_builder.h"
#include "processing/image_processor.h"

GUI &GUI::get_instance()
{
    static GUI instance;
    return instance;
}

GUI::GUI()
{
    this->window = UIBuilder::get_instance().get_widget<Gtk::Window>("appWindow");

    this->imageView = UIBuilder::get_instance().get_widget<Gtk::Picture>("imageView");
    this->originalImageView = UIBuilder::get_instance().get_widget<Gtk::Picture>("originalImageView");

    this->effectsTextView = UIBuilder::get_instance().get_widget<Gtk::TextView>("effectsTextView");

    this->beforeLabel = UIBuilder::get_instance().get_widget<Gtk::Label>("beforeLabel");
    this->afterLabel = UIBuilder::get_instance().get_widget<Gtk::Label>("afterLabel");

    this->applyEffectsButton = UIBuilder::get_instance().get_widget<Gtk::Button>("applyEffectsButton");
    this->exportImageButton = UIBuilder::get_instance().get_widget<Gtk::Button>("exportImageButton");
    this->dualViewToggleButton = UIBuilder::get_instance().get_widget<Gtk::ToggleButton>("dualViewToggleButton");
    this->beforeAfterToggleButton = UIBuilder::get_instance().get_widget<Gtk::ToggleButton>("beforeAfterToggleButton");

    is_original_image_shown = false;

    load_css();
    load_dark_theme();
}

void GUI::set_initial_widget_sensitivity()
{
    this->applyEffectsButton->set_sensitive(false);
    this->exportImageButton->set_sensitive(false);   
}

Gtk::Window *GUI::get_main_window()
{
    return this->window;
}

Gtk::TextView *GUI::get_effects_text_view()
{
    return this->effectsTextView;
}

Gtk::Button *GUI::get_apply_effects_button()
{
    return this->applyEffectsButton;
}

Gtk::Button *GUI::get_export_image_button()
{
    return this->exportImageButton;
}

void GUI::load_css()
{
    auto provider = Gtk::CssProvider::create();
    provider->load_from_resource("css/style.css");

    this->window->get_style_context()
        ->add_provider_for_display(
            window->get_display(),
            provider,
            GTK_STYLE_PROVIDER_PRIORITY_USER);
}

void GUI::load_dark_theme()
{
    Gtk::Settings::get_default()
        ->set_property(
            "gtk-application-prefer-dark-theme",
            true);
}

void GUI::set_picture()
{
    redraw_picture();

    this->originalImageView->set_pixbuf(
        ImageProcessor::get_instance().copy_original_pixbuf());

    this->originalImageView->set_visible(false);
    this->exportImageButton->set_sensitive(true);
}

void GUI::redraw_picture()
{
    this->imageView->set_pixbuf(ImageProcessor::get_instance().get_pixbuf());
}

void GUI::toggle_before_after()
{
    if (is_original_image_shown)
        this->imageView->set_pixbuf(ImageProcessor::get_instance().get_pixbuf());

    else
        this->imageView->set_pixbuf(ImageProcessor::get_instance().copy_original_pixbuf());

    this->beforeAfterToggleButton->set_active(!is_original_image_shown);

    is_original_image_shown = !is_original_image_shown;
}

void GUI::toggle_dual_view()
{
    bool is_original_image_shown = !this->originalImageView->get_visible();

    this->originalImageView->set_visible(is_original_image_shown);

    this->beforeLabel->set_visible(is_original_image_shown);
    this->afterLabel->set_visible(is_original_image_shown);

    this->dualViewToggleButton->set_active(this->originalImageView->get_visible());
}