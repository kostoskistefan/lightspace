#ifndef IMAGE_DATA_H
#define IMAGE_DATA_H

#include <gtkmm.h>

class ImageData
{
public:
    ImageData(guchar *pixels, guint width, guint height, guint rowstride, guint n_channels)
        : pixels(pixels), width(width), height(height), rowstride(rowstride), n_channels(n_channels) {}

    guchar *pixels;
    guint width;
    guint height;
    guint rowstride;
    guint n_channels;
    
    bool is_valid();
    static ImageData get_pixbuf_image_data(Glib::RefPtr<Gdk::Pixbuf> pixbuf);
};


#endif