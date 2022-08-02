#include "image_dialog.h"
#include "image_processor.h"
#include "ui_builder.h"

ImageDialog::ImageDialog(Gtk::Window *parent, std::string title)
{
    dialog = new Gtk::FileChooserDialog(
        *parent,
        title);
}

ImageDialog::~ImageDialog()
{
    delete dialog;
}

void ImageDialog::open_image()
{
    dialog->add_button("Open", Gtk::ResponseType::ACCEPT);
    dialog->add_button("Cancel", Gtk::ResponseType::CANCEL);

    dialog->set_modal(true);

    auto filterImages = Gtk::FileFilter::create();
    filterImages->set_name("Image Files");
    filterImages->add_mime_type("image/jpeg");
    filterImages->add_mime_type("image/png");

    dialog->set_filter(filterImages);

    dialog->signal_response().connect([=](int response){ open_image_callback(response); });

    dialog->show();
}

void ImageDialog::open_image_callback(int response)
{
    dialog->hide();

    if (response != Gtk::ResponseType::ACCEPT)
        return;

    auto filePath = dialog->get_file()->get_path();
    auto pixbuf = Gdk::Pixbuf::create_from_file(filePath);

    ImageProcessor::get_instance().set_original_pixbuf(pixbuf);
}
