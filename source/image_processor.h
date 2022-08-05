#ifndef IMAGE_PROCESSOR_H
#define IMAGE_PROCESSOR_H

#include <gtkmm.h>

class ImageProcessor
{
public:
    static ImageProcessor &get_instance();

    Glib::RefPtr<Gdk::Pixbuf> get_pixbuf();
    Glib::RefPtr<Gdk::Pixbuf> copy_original_pixbuf();

    void set_pixbuf(Glib::RefPtr<Gdk::Pixbuf> pixbuf);
    void set_original_pixbuf(Glib::RefPtr<Gdk::Pixbuf> pixbuf);

    void restore_to_original_pixbuf();
    void apply_effects();

private:
    ImageProcessor();
    ImageProcessor(ImageProcessor const &);
    void operator=(ImageProcessor const &);
    Glib::RefPtr<Gdk::Pixbuf> pixbuf;
    Glib::RefPtr<Gdk::Pixbuf> originalPixbuf;
};

#endif // IMAGE_PROCESSOR_H
