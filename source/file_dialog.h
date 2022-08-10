#ifndef FILE_DIALOG_H
#define FILE_DIALOG_H

#include <gtkmm.h>

class FileDialog
{
public:
    FileDialog(Gtk::Window *parent);
    ~FileDialog();

    void open_file_dialog();
    void export_file_dialog();

    sigc::signal<void(std::string, Gtk::FileChooser::Action)> signal_dialog_success();

protected:
    sigc::signal<void(std::string, Gtk::FileChooser::Action)> signalDialogSuccess;

private:
    std::shared_ptr<Gtk::FileChooserNative> dialog;

    void set_filter();
    void emit_signal_based_on_response(int response);
};

#endif // FILE_DIALOG_H