#include "image_processor.h"
#include "ui_builder.h"
#include "effect_data_parser.h"

ImageProcessor &ImageProcessor::get_instance()
{
    static ImageProcessor instance;
    return instance;
}

ImageProcessor::ImageProcessor()
{
    this->imageView = UIBuilder::get_instance()
                          .get_widget<Gtk::Picture>("imageView");

    this->originalImageView = UIBuilder::get_instance()
                                  .get_widget<Gtk::Picture>("originalImageView");

    is_original_image_shown = false;
}

void ImageProcessor::set_pixbuf(Glib::RefPtr<Gdk::Pixbuf> pixbuf)
{
    this->pixbuf = pixbuf;
}

Glib::RefPtr<Gdk::Pixbuf> ImageProcessor::get_pixbuf()
{
    return this->pixbuf;
}

void ImageProcessor::set_original_pixbuf(Glib::RefPtr<Gdk::Pixbuf> pixbuf)
{
    this->originalPixbuf = pixbuf;

    restore_to_original_pixbuf();
    this->imageView->set_pixbuf(this->pixbuf);
    this->originalImageView->set_pixbuf(this->originalPixbuf);
    this->originalImageView->set_visible(false);
}

void ImageProcessor::toggle_before_after()
{
    if (this->originalImageView->get_visible())
        return;

    if (is_original_image_shown)
        this->imageView->set_pixbuf(this->pixbuf);

    else
        this->imageView->set_pixbuf(this->originalPixbuf);

    UIBuilder::get_instance()
        .get_widget<Gtk::ToggleButton>("beforeAfterToggleButton")
        ->set_active(!is_original_image_shown);

    is_original_image_shown = !is_original_image_shown;
}

void ImageProcessor::toggle_dual_view()
{
    this->originalImageView->set_visible(
        !this->originalImageView->get_visible());

    auto beforeLabel = UIBuilder::get_instance()
                           .get_widget<Gtk::Label>("beforeLabel");

    auto afterLabel = UIBuilder::get_instance()
                          .get_widget<Gtk::Label>("afterLabel");

    beforeLabel->set_visible(this->originalImageView->get_visible());

    afterLabel->set_visible(this->originalImageView->get_visible());

    UIBuilder::get_instance()
        .get_widget<Gtk::ToggleButton>("dualViewToggleButton")
        ->set_active(this->originalImageView->get_visible());
}

void ImageProcessor::restore_to_original_pixbuf()
{
    g_return_if_fail(this->originalPixbuf);

    this->pixbuf = this->originalPixbuf.get()->copy();
}

void ImageProcessor::apply_effects()
{
    g_return_if_fail(this->originalPixbuf != nullptr);

    restore_to_original_pixbuf();
    parse_effect_data();

    this->imageView->set_pixbuf(this->pixbuf);
}
