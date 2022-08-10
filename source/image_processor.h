#ifndef IMAGE_PROCESSOR_H
#define IMAGE_PROCESSOR_H

#include <gtkmm.h>
#include "effect.h"

class ImageProcessor
{
public:
    ImageProcessor();

    void open_image(const std::shared_ptr<Gdk::Pixbuf> pixbuf);

    void set_pixbuf(const std::shared_ptr<Gdk::Pixbuf> pixbuf);
    void set_original_pixbuf(const std::shared_ptr<Gdk::Pixbuf> pixbuf);

    // TODO: Change return type to avoid unnecessary shared_ptr overhead
    std::shared_ptr<Gdk::Pixbuf> get_processed_pixbuf();
    
    // TODO: Change return type to avoid unnecessary shared_ptr overhead
    std::shared_ptr<Gdk::Pixbuf> copy_original_pixbuf();

    void process_image(std::vector<effect_t> effects);
    void save_image(std::string filePath, std::string format);

private:
    std::shared_ptr<Gdk::Pixbuf> pixbuf;
    std::shared_ptr<Gdk::Pixbuf> originalPixbuf;
};

#endif // IMAGE_PROCESSOR_H