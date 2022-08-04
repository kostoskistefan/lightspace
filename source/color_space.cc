#include "color_space.h"

/**
 * Create a rgb_color_t object with all fields set to 0
 * @brief Default constructor
 * @see rgb_color_t(guint8 value)
 * @see rgb_color_t(guint8 r, guint8 g, guint8 b)
 */
rgb_color::rgb_color()
{
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

/**
 * Create a rgb_color_t object with all fields set to the given value
 * @brief Constructor
 * @param value The value to set all fields to
 * @see rgb_color_t()
 * @see rgb_color_t(guint8 r, guint8 g, guint8 b)
 */
rgb_color::rgb_color(guint8 value)
{
    this->r = value;
    this->g = value;
    this->b = value;
}

/**
 * Create a rgb_color_t object from red, green and blue values
 * @brief Constructor
 * @see rgb_color_t()
 * @see rgb_color_t(guint8 value)
 */
rgb_color::rgb_color(guint8 r, guint8 g, guint8 b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

/**
 * Create a hsb_color_t object with all fields set to 0
 * @brief Default constructor
 * @see hsb_color_t(double value)
 * @see hsb_color_t(double h, double s, double v)
 */
hsb_color::hsb_color()
{
    this->h = 0;
    this->s = 0;
    this->b = 0;
}

/**
 * Create a hsb_color_t object with all fields set to the given value
 * @brief Constructor
 * @param value The value to set all fields to
 * @see hsb_color_t()
 * @see hsb_color_t(double h, double s, double v)
 */
hsb_color::hsb_color(double value)
{
    this->h = value;
    this->s = value;
    this->b = value;
}

/**
 * Create a hsb_color_t object from hue, saturation and brightness values
 * @brief Constructor
 * @see hsb_color_t()
 * @see hsb_color_t(double value)
 */
hsb_color::hsb_color(double h, double s, double b)
{
    this->h = h;
    this->s = s;
    this->b = b;
}

/**
 *  @brief Convert an HSB color to an RGB color.
 *  @param hsbColor The HSB color to convert. Values are in the range [0.00, 1.00].
 *  @return The converted RGB color object.
 */
rgb_color_t hsb_to_rgb(hsb_color_t hsbColor)
{
    if (hsbColor.s == 0)
        return rgb_color_t(hsbColor.b * 255);

    rgb_color_t rgbColor;

    hsbColor.h = hsbColor.h - floor(hsbColor.h);

    int i = floor(hsbColor.h * 6);

    float f = hsbColor.h * 6 - i;
    float p = hsbColor.b * (1 - hsbColor.s);
    float q = hsbColor.b * (1 - f * hsbColor.s);
    float t = hsbColor.b * (1 - (1 - f) * hsbColor.s);

    p *= 255;
    q *= 255;
    t *= 255;
    hsbColor.b *= 255;

    switch (i)
    {
    case 0:
        rgbColor.r = hsbColor.b;
        rgbColor.g = t;
        rgbColor.b = p;
        break;
    case 1:
        rgbColor.r = q;
        rgbColor.g = hsbColor.b;
        rgbColor.b = p;
        break;
    case 2:
        rgbColor.r = p;
        rgbColor.g = hsbColor.b;
        rgbColor.b = t;
        break;
    case 3:
        rgbColor.r = p;
        rgbColor.g = q;
        rgbColor.b = hsbColor.b;
        break;
    case 4:
        rgbColor.r = t;
        rgbColor.g = p;
        rgbColor.b = hsbColor.b;
        break;
    case 5:
        rgbColor.r = hsbColor.b;
        rgbColor.g = p;
        rgbColor.b = q;
        break;
    }

    return rgbColor;
}

/**
 *  @brief Convert an RGB color to an HSB color.
 *  @param rgbColor The RGB color to convert. Values are in the range [0, 255].
 *  @return The converted HSB color object.
 */
hsb_color_t rgb_to_hsb(rgb_color_t rgbColor)
{
    hsb_color_t hsbColor;

    int min = MIN(rgbColor.r, MIN(rgbColor.g, rgbColor.b));
    int max = MAX(rgbColor.r, MAX(rgbColor.g, rgbColor.b));

    hsbColor.b = max / 255.0f;

    if (max == 0)
        hsbColor.s = 0;

    else
        hsbColor.s = ((float)(max - min)) / ((float)max);

    if (hsbColor.s == 0)
        hsbColor.h = 0;

    else
    {
        float delta = (max - min) * 6;

        if (rgbColor.r == max)
            hsbColor.h = (rgbColor.g - rgbColor.b) / delta;

        else if (rgbColor.g == max)
            hsbColor.h = 1.0f / 3 + (rgbColor.b - rgbColor.r) / delta;

        else
            hsbColor.h = 2.0f / 3 + (rgbColor.r - rgbColor.g) / delta;

        if (hsbColor.h < 0)
            hsbColor.h++;
    }

    return hsbColor;
}
