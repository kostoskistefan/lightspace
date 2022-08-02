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
    this->imageView = static_cast<Gtk::Picture *>(
        UIBuilder::get_instance().get_widget_from_id("imageView"));
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

    if (this->pixbuf == nullptr)
    {
        restore_to_original_pixbuf();
        this->imageView->set_pixbuf(this->pixbuf);
    }
}

void ImageProcessor::restore_to_original_pixbuf()
{
    this->pixbuf = this->originalPixbuf.get()->copy();
}

void ImageProcessor::apply_effects()
{
    restore_to_original_pixbuf();
    parse_effect_data();

    this->imageView->set_pixbuf(this->pixbuf);
}
