#include "image_dialog.h"
#include "image_processor.h"
#include "ui_builder.h"
#include "gui.h"

ImageDialog::ImageDialog()
{
    dialog = Gtk::FileChooserNative::create("", Gtk::FileChooser::Action::OPEN, "", "Cancel");
    dialog->set_modal(true);
    add_dialog_file_filter();
}

ImageDialog::~ImageDialog() {}

void ImageDialog::set_parent(Gtk::Window *parent)
{
    this->dialog->set_transient_for(*parent);
}

void ImageDialog::set_title(std::string title)
{
    this->dialog->set_title(title);
}

void ImageDialog::set_action(Gtk::FileChooser::Action action)
{
    this->dialog->set_action(action);
}

void ImageDialog::add_dialog_file_filter()
{
    auto filterImages = Gtk::FileFilter::create();
    filterImages->set_name("Image Files");
    filterImages->add_mime_type("image/jpeg");
    filterImages->add_mime_type("image/png");

    dialog->set_filter(filterImages);
}

void ImageDialog::open_image()
{
    dialog->signal_response().connect([=](int response)
                                      { open_image_callback(response); });

    dialog->show();
}

void ImageDialog::export_image()
{
    dialog->set_current_name("untitled.png");

    dialog->signal_response().connect([=](int response)
                                      { save_image_callback(response); });

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
    GUI::get_instance().set_picture();
}

void ImageDialog::save_image_callback(int response)
{
    dialog->hide();

    if (response != Gtk::ResponseType::ACCEPT)
        return;

    auto filePath = dialog->get_file()->get_path();

    ImageProcessor::get_instance().get_pixbuf()->save(filePath, "png");
}