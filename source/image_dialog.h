#ifndef IMAGE_DIALOG_H
#define IMAGE_DIALOG_H

#include <gtkmm.h>

class ImageDialog
{
public:
    ImageDialog(
        Gtk::Window *parent, 
        std::string title, 
        Gtk::FileChooser::Action action);
        
    ~ImageDialog();
    
    void open_image();
    void save_image();

private:
    Glib::RefPtr<Gtk::FileChooserNative> dialog;
    void open_image_callback(int response);
    void save_image_callback(int response);
    void add_dialog_file_filter();
};

#endif