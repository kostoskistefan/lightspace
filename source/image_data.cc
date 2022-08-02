#include "image_data.h"

bool pixbuf_is_valid(Glib::RefPtr<Gdk::Pixbuf> pixbuf)
{
    g_return_val_if_fail(pixbuf != nullptr, false);

    g_return_val_if_fail(pixbuf->get_colorspace() == Gdk::Colorspace::RGB, false);
    g_return_val_if_fail(pixbuf->get_bits_per_sample() == 8, false);
    g_return_val_if_fail(pixbuf->get_n_channels() == 3, false);

    return true;
}

bool ImageData::is_valid()
{
    g_return_val_if_fail(this->pixels != nullptr, false);
    g_return_val_if_fail(this->width > 0, false);
    g_return_val_if_fail(this->height > 0, false);
    g_return_val_if_fail(this->rowstride > 0, false);
    g_return_val_if_fail(this->n_channels > 0, false);

    return true;
}

ImageData ImageData::get_pixbuf_image_data(Glib::RefPtr<Gdk::Pixbuf> pixbuf)
{
    g_return_val_if_fail(pixbuf_is_valid(pixbuf), ImageData(nullptr, 0, 0, 0, 0));

    guchar *pixels = pixbuf->get_pixels();
    guint width = pixbuf->get_width();
    guint height = pixbuf->get_height();
    guint rowstride = pixbuf->get_rowstride();
    guint n_channels = pixbuf->get_n_channels();

    return ImageData(pixels, width, height, rowstride, n_channels);
}