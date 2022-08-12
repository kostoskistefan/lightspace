#include "histogram.h"
#include "../image.h"
#include "../histogram_data.h"
#include <cstdlib>

Histogram::Histogram()
{
    this->set_draw_func(sigc::mem_fun(*this, &Histogram::on_draw));
    this->set_size_request(200, 125);
    this->set_hexpand(true);
}

void Histogram::set_pixbuf(const std::shared_ptr<Gdk::Pixbuf> &pixbuf)
{
    this->pixbuf = pixbuf;
}

Histogram::~Histogram() {}

void set_context_color_from_channel(const Cairo::RefPtr<Cairo::Context> &cr, int8_t channel)
{
    Gdk::RGBA color;
    
    switch (channel)
    {
    case 0:
        color.set_rgba(1, 0, 0, 0.3);
        break;
    
    case 1:
        color.set_rgba(0, 1, 0, 0.3);
        break;

    case 2:
        color.set_rgba(0, 0, 1, 0.3);
        break;

    default:
        color.set("dimgrey");
        break;
    }
    
    cr->set_source_rgba(color.get_red(), color.get_green(), color.get_blue(), color.get_alpha());
}

void Histogram::on_draw(const std::shared_ptr<Cairo::Context> &cr, int width, int height)
{
    (void)width;
    (void)height;

    cr->set_source_rgba(0, 0, 0, 0.1);
    cr->set_line_width(this->get_width() / 200.0f);
    // cr->set_line_cap(Cairo::Context::LineCap::ROUND);
    cr->paint();

    if (this->pixbuf == nullptr)
        return;

    Image image(this->pixbuf);

    if (!image.is_valid())
        return;

    HistogramData histogramData(image);

    #define HISTOGRAM_TOP_PADDING 10

    double scaleX = 1.0 / histogramData.get_channel_size() * this->get_width();

    // TODO: Fix vertical scaling for the histogram
    double scaleY = 1.0 / (histogramData.get_average() * 5) * (this->get_height() - HISTOGRAM_TOP_PADDING);

    for (uint8_t channel = 0; channel < image.channels; channel++)
    {
        if (image.channels == 1)
            set_context_color_from_channel(cr, -1);

        else 
            set_context_color_from_channel(cr, channel);

        for (uint32_t i = 0; i < histogramData.get_channel_size(); i++)
        {
            cr->move_to(i * scaleX, this->get_height());
            cr->line_to(i * scaleX, this->get_height() - histogramData.at(channel, i) * scaleY);
        }

        cr->stroke();
    }
}