#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <gdkmm/pixbuf.h>
#include <gtkmm/drawingarea.h>
#include <cairomm/context.h>

/**
 * @class Histogram
 * @brief Widget to display a histogram of an image.
 */
class Histogram : public Gtk::DrawingArea
{
public:
    /**
     * @brief Default constructor
     * @details Creates a new Histogram widget.
     */
    Histogram();

    /**
     * @brief Destructor
     * @details Destroys the widget.
     */
    virtual ~Histogram();

    /**
     * @brief Sets the pointer to the pixbuf to be displayed in the histogram.
     * @param pixbuf The pixbuf to be displayed.
     */
    void set_pixbuf(const std::shared_ptr<Gdk::Pixbuf> &pixbuf);

protected:
    /**
     * @brief Draws the histogram.
     * @param cr The Cairo context to draw on.
     * @param width The width of the widget.
     * @param height The height of the widget.
     */
    void on_draw(const std::shared_ptr<Cairo::Context> &cr, int width, int height);

private:
    std::shared_ptr<Gdk::Pixbuf> pixbuf;
};

#endif // HISTOGRAM_H