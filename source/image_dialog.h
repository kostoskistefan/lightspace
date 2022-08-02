#ifndef IMAGE_DIALOG_H
#define IMAGE_DIALOG_H

#include <gtkmm.h>

class ImageDialog
{
public:
    ImageDialog(Gtk::Window *parent, std::string title);
    ~ImageDialog();
    
    void open_image();

private:
    Gtk::FileChooserDialog *dialog;
    void open_image_callback(int response);
};

#endif