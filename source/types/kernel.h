#ifndef KERNEL_H
#define KERNEL_H

#include <cstdint>

/**
 * @class Kernel
 * @brief Class to store kernel data used for image manipulation.
 */
class Kernel
{
public:
    /**
     * @brief Constructor
     * @details Creates a new Kernel object of given size.
     * @param size The size of the kernel.
     */
    Kernel(uint8_t size);

    /**
     * @brief Destructor
     * @details Deallocates the data array.
     */
    ~Kernel();

    /**
     * @brief Get the kernel data at index.
     * @param index The index to get the kernel data for.
     * @return A reference to the kernel data at index.
     */
    float &at(uint8_t x, uint8_t y);

    /**
     * @brief Get the size of the kernel.
     * @return The size of the kernel.
     */
    uint8_t get_size();

private:
    float *data;
    uint8_t size;
};

#endif // KERNEL_H