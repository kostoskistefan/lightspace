#include "image_processor.h"
#include "effect_processor.h"

ImageProcessor::ImageProcessor() {}

void ImageProcessor::open_image(const std::shared_ptr<Gdk::Pixbuf> pixbuf)
{
    this->pixbuf = pixbuf->copy();
    this->originalPixbuf = pixbuf;
}

std::shared_ptr<Gdk::Pixbuf> ImageProcessor::get_processed_pixbuf()
{
    g_return_val_if_fail(this->pixbuf != nullptr, nullptr);

    return this->pixbuf;
}

std::shared_ptr<Gdk::Pixbuf> ImageProcessor::copy_original_pixbuf()
{
    g_return_val_if_fail(this->originalPixbuf != nullptr, nullptr);

    return this->originalPixbuf->copy();
}

void ImageProcessor::restore_original_pixels()
{
    Image original(this->originalPixbuf);
    Image processed(this->pixbuf);

    processed.copy_pixels(original);
}

void ImageProcessor::process_image(std::vector<std::pair<std::string, double>> &effects)
{
    g_return_if_fail(this->pixbuf != nullptr);

    restore_original_pixels();

    Image image(this->pixbuf);

    EffectProcessor::apply(image, effects);

    this->signalProcessingChanged.emit();
}

void ImageProcessor::save_image(std::string filePath, std::string format)
{
    this->pixbuf->save(filePath, format);
}

sigc::signal<void()> ImageProcessor::signal_processing_changed()
{
    return this->signalProcessingChanged;
}
