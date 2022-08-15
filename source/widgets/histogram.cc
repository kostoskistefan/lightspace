#include "histogram.h"
#include <cstdlib>

Histogram::Histogram()
{
    this->set_draw_func(sigc::mem_fun(*this, &Histogram::on_draw));
    this->set_size_request(200, 125);
    this->set_hexpand(true);
}

void Histogram::set_pixbuf(const std::shared_ptr<Gdk::Pixbuf> &pixbuf)
{    
    g_return_if_fail(pixbuf != nullptr);

    this->image = new Image(pixbuf);

    g_return_if_fail(this->image->is_valid());

    this->histogramData = new HistogramData(*this->image);
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
    cr->set_source_rgba(0, 0, 0, 0.1f);
    cr->paint();

    if (this->image == nullptr || !this->image->is_valid())
        return;

    histogramData->update();

    uint32_t colorsPerPixel = this->image->get_colors_per_pixel();

    cr->translate(0.0f, height);
    cr->scale(
        1.0 / colorsPerPixel * width,
        -height / (float)this->histogramData->get_highest_value());

    for (uint8_t channel = 0; channel < this->image->channels; channel++)
    {
        if (this->image->channels == 1)
            set_context_color_from_channel(cr, -1);

        else
            set_context_color_from_channel(cr, channel);

        for (uint32_t i = 0; i < colorsPerPixel; i++)
        {
            cr->move_to(i, 0);
            cr->line_to(i, this->histogramData->at(channel, i));
        }

        cr->stroke();
    }
}
