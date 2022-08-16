#ifndef IMAGE_PROCESSOR_H
#define IMAGE_PROCESSOR_H

#include <gdkmm/pixbuf.h>
#include "types/effect.h"

/**
 * @class ImageProcessor
 * @brief Handles the image processing logic.
 */
class ImageProcessor
{
public:
    /**
     * @brief Constructor.
     */
    ImageProcessor();

    /**
     * @brief Set the internal pixel buffer to the opened image.
     * @param pixbuf The pixel bufer of the opened image.
     */
    void open_image(const std::shared_ptr<Gdk::Pixbuf> pixbuf);

    /**
     * @brief Get the processed image.
     * @return The processed pixel buffer.
     */
    std::shared_ptr<Gdk::Pixbuf> get_processed_pixbuf();

    /**
     * @brief Get the original image.
     * @return The original pixel buffer.
     */
    std::shared_ptr<Gdk::Pixbuf> copy_original_pixbuf();

    /**
     * @brief Apply the given effect to the image.
     * @param effect The list of effects to apply to the image.
     */
    void process_image(std::vector<effect_t> effects);

    /**
     * @brief Save the image to the given file path.
     * @param filePath The file path to save the image to.
     * @param format The format to save the image in.
     * @note Currently it saves to jpeg format only.
     * @todo Add more save formats and parameters like "quality".
     */
    void save_image(std::string filePath, std::string format);

    /**
     * @brief Restore the pixels of the processed image to the original one.
     */
    void restore_original_pixels();

    /**
     * @brief Signal that is emitted after the image is processed.
     */
    sigc::signal<void()> signal_processing_changed();

protected:
    sigc::signal<void()> signalProcessingChanged;

private:
    std::shared_ptr<Gdk::Pixbuf> pixbuf;
    std::shared_ptr<Gdk::Pixbuf> originalPixbuf;
};

#endif // IMAGE_PROCESSOR_H
