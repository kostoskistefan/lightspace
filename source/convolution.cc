#include "convolution.h"

void convolve(Image image, kernel_t kernel)
{
    // Convolution based on http://www.songho.ca/dsp/convolution/convolution2d_example.html

    // Create a blank image to store the output of the convolution.
    Image output(image);
    output.pixels = new uint8_t[image.width * image.height * image.channels];

    // Get the center of the kernel.
    int center = (kernel.size - 1) / 2;

    // Loop through each channel of the image.
    for (int channel = 0; channel < image.channels; channel++)
    {
        // Iterate through each pixel in the image.
        for (int x = 0; x < image.width; x++)
        {
            for (int y = 0; y < image.height; y++)
            {
                float value = 0;

                // Iterate through each pixel in the kernel.
                for (int i = -center; i <= center; i++)
                {
                    int x2 = x + i;

                    // If the x2 value is out of bounds, continue to the next iteration.
                    if (x2 < 0 || x2 >= image.width)
                        continue;

                    for (int j = -center; j <= center; j++)
                    {
                        int y2 = y + j;

                        // If the y2 value is out of bounds, continue to the next iteration.
                        if (y2 < 0 || y2 >= image.height)
                            continue;

                        // Get the value of the kernel at the current position.
                        float kernelValue = kernel.data[(i + center) * kernel.size + (j + center)];

                        // Iterate through each channel in the image.
                        // for (int channel = 0; channel < image.channels; channel++)
                        // {
                        // Get the value of the pixel at the current position for the current channel.
                        uint8_t pixelValue = image.pixels[y2 * image.rowstride + x2 * image.channels + channel];

                        // Get value for the current pixel based on the kernel
                        value += kernelValue * pixelValue;
                        // }
                    }
                }

                // Add the value of the convoluted pixel to the output image.
                output.pixels[y * image.rowstride + x * image.channels + channel] = CLAMP(value, 0, 255);
            }
        }
    }

    for (int x = 0; x < image.width; x++)
        for (int y = 0; y < image.height; y++)
            for (int channel = 0; channel < image.channels; channel++)
                image.pixels[y * image.rowstride + x * image.channels + channel] =
                    output.pixels[y * image.rowstride + x * image.channels + channel];
}
