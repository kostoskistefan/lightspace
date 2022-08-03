#ifndef IMAGE_DIALOG_H
#define IMAGE_DIALOG_H

#include <gtkmm.h>

class ImageDialog
{
public:
    ImageDialog();
    ~ImageDialog();

    void set_parent(Gtk::Window *parent);
    void set_title(std::string title);
    void set_action(Gtk::FileChooser::Action action);
    
    void open_image();
    void export_image();

private:
    Glib::RefPtr<Gtk::FileChooserNative> dialog;
    void open_image_callback(int response);
    void save_image_callback(int response);
    void add_dialog_file_filter();
};

#endif