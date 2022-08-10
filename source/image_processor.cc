#include "image_processor.h"
#include "effects/contrast.h"

ImageProcessor::ImageProcessor() {}

void ImageProcessor::open_image(const std::shared_ptr<Gdk::Pixbuf> pixbuf)
{
    this->set_pixbuf(pixbuf);
    this->set_original_pixbuf(pixbuf->copy());
}

void ImageProcessor::set_pixbuf(const std::shared_ptr<Gdk::Pixbuf> pixbuf)
{
    this->pixbuf = pixbuf;
}

void ImageProcessor::set_original_pixbuf(const std::shared_ptr<Gdk::Pixbuf> pixbuf)
{
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

void ImageProcessor::process_image(std::vector<effect_t> effects)
{
    g_return_if_fail(this->pixbuf != nullptr);

    this->pixbuf = this->originalPixbuf->copy();

    Image image(this->pixbuf);

    for (auto effect : effects)
    {
        if (effect.name == "contrast")
            Contrast::apply(image, effect.amount);
    }
}

void ImageProcessor::save_image(std::string filePath, std::string format)
{
    // TODO: Add more save formats and parameters like "quality"
    this->pixbuf->save(filePath, format); 
}