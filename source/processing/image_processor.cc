#include "image_processor.h"
#include "../ui_builder.h"
#include "../effect_data_parser.h"

ImageProcessor &ImageProcessor::get_instance()
{
    static ImageProcessor instance;
    return instance;
}

ImageProcessor::ImageProcessor() {}

void ImageProcessor::set_pixbuf(Glib::RefPtr<Gdk::Pixbuf> pixbuf)
{
    this->pixbuf = pixbuf;
}

Glib::RefPtr<Gdk::Pixbuf> ImageProcessor::get_pixbuf()
{
    return this->pixbuf;
}

Glib::RefPtr<Gdk::Pixbuf> ImageProcessor::copy_original_pixbuf()
{
    return this->originalPixbuf.get()->copy();
}

void ImageProcessor::set_original_pixbuf(Glib::RefPtr<Gdk::Pixbuf> pixbuf)
{
    this->originalPixbuf = pixbuf;

    restore_to_original_pixbuf();
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
}
