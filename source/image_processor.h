#ifndef IMAGE_PROCESSOR_H
#define IMAGE_PROCESSOR_H

#include <gdkmm/pixbuf.h>
#include "types/effect.h"

class ImageProcessor
{
public:
    ImageProcessor();

    void open_image(const std::shared_ptr<Gdk::Pixbuf> pixbuf);

    std::shared_ptr<Gdk::Pixbuf> get_processed_pixbuf();
    std::shared_ptr<Gdk::Pixbuf> copy_original_pixbuf();

    void process_image(std::vector<effect_t> effects);
    void save_image(std::string filePath, std::string format);

    void restore_original_pixels();

    sigc::signal<void()> signal_processing_changed();

protected:
    sigc::signal<void()> signalProcessingChanged;

private:
    std::shared_ptr<Gdk::Pixbuf> pixbuf;
    std::shared_ptr<Gdk::Pixbuf> originalPixbuf;
};

#endif // IMAGE_PROCESSOR_H
