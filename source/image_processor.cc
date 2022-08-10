#include "image_processor.h"

ImageProcessor::ImageProcessor() {}

void ImageProcessor::open_image(const std::shared_ptr<Gdk::Pixbuf> pixbuf)
{
    this->set_pixbuf(pixbuf);
    this->set_original_pixbuf(pixbuf);
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
    return this->pixbuf;
}

std::shared_ptr<Gdk::Pixbuf> ImageProcessor::copy_original_pixbuf()
{
    return this->originalPixbuf->copy();
}

void ImageProcessor::process_image(std::vector<effect_t> effects)
{
    for (auto effect : effects)
    {
        // effect.apply();
    }
}

void ImageProcessor::save_image(std::string filePath, std::string format)
{
    // TODO: Add more save formats and parameters like "quality"
    this->pixbuf->save(filePath, format); 
}