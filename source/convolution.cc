#include "convolution.h"

#ifdef _OPENMP
#include <omp.h>
#endif

void convolve(Image &image, Kernel &kernel)
{
    // Convolution based on http://www.songho.ca/dsp/convolution/convolution2d_example.html

    // Create a blank image to store the output of the convolution.
    Image buffer(image);
    buffer.pixels = new uint8_t[image.width * image.height * image.channels];

    // Get the center of the kernel.
    int center = (kernel.get_size() - 1) / 2;

#ifdef _OPENMP
#pragma omp parallel for collapse(3)
#endif

    for (int channel = 0; channel < image.channels; channel++)
    {
        for (int x = 0; x < image.width; x++)
        {
            for (int y = 0; y < image.height; y++)
            {
                float value = 0;

                // Iterate through each row of the kernel.
                for (int i = -center; i <= center; i++)
                {
                    int x2 = x + i;

                    // If the x2 value is out of bounds, continue to the next iteration.
                    if (x2 < 0 || x2 >= image.width)
                        continue;

                    // Iterate through each column of the kernel.
                    for (int j = -center; j <= center; j++)
                    {
                        int y2 = y + j;

                        // If the y2 value is out of bounds, continue to the next iteration.
                        if (y2 < 0 || y2 >= image.height)
                            continue;

                        // Get the value of the kernel at the current position.
                        float kernelValue = kernel.at(i + center, j + center);

                        // Set the value for the current pixel based on the kernel
                        value += kernelValue * image.at(x2, y2, channel);
                    }
                }

                // Add the value of the convoluted pixel to the buffer image.
                buffer.at(x, y, channel) = CLAMP(value, 0, 255);
            }
        }
    }

    image.copy_pixels(buffer);
    
    delete buffer.pixels;
}
