#ifndef FILE_DIALOG_H
#define FILE_DIALOG_H

#include <gtkmm/window.h>
#include <gtkmm/filechooser.h>
#include <gtkmm/filechoosernative.h>

/**
 * @class FileDialog
 * @brief A file dialog for opening or saving image files.
 */
class FileDialog
{
public:
    /**
     * @brief Constructor.
     * @param parent The parent window of the dialog.
     * @return The file dialog object.
     */
    FileDialog(Gtk::Window *parent);

    /**
     * @brief Configure the dialog to open an image.
     */
    void open_file_dialog();

    /**
     * @brief Configure the dialog to export an image.
     */
    void export_file_dialog();

    /**
     * @brief Emit a signal based on the response of the dialog (open or save).
     */
    sigc::signal<void(std::string, Gtk::FileChooser::Action)> signal_dialog_success();

protected:
    sigc::signal<void(std::string, Gtk::FileChooser::Action)> signalDialogSuccess;

private:
    std::shared_ptr<Gtk::FileChooserNative> dialog;

    /**
     * @brief Set a filter for the dialog to only allow image files.
     */
    void set_filter();

    /**
     * @brief Trigger the signal emit function based on the response of the dialog.
     */
    void emit_signal_based_on_response(int response);
};

#endif // FILE_DIALOG_H