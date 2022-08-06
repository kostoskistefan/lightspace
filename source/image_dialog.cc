#include "image_dialog.h"
#include "processing/image_processor.h"
#include "ui_builder.h"
#include "gui.h"

ImageDialog::ImageDialog(Gtk::Window *parent)
{
    dialog = Gtk::FileChooserNative::create("", Gtk::FileChooser::Action::OPEN, "", "Cancel");
    dialog->set_modal(true);
    dialog->set_transient_for(*parent);
    add_dialog_file_filter();
}

ImageDialog::~ImageDialog() 
{
    delete &dialog;
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

static void open_image_callback(int response, Glib::RefPtr<Gtk::FileChooserNative> dialog)
{
    dialog->hide();

    if (response != Gtk::ResponseType::ACCEPT)
        return;

    auto filePath = dialog->get_file()->get_path();
    auto pixbuf = Gdk::Pixbuf::create_from_file(filePath);

    ImageProcessor::get_instance().set_original_pixbuf(pixbuf);
    GUI::get_instance().set_picture();
}

static void export_image_callback(int response, Glib::RefPtr<Gtk::FileChooserNative> dialog)
{
    dialog->hide();

    if (response != Gtk::ResponseType::ACCEPT)
        return;

    auto filePath = dialog->get_file()->get_path();

    ImageProcessor::get_instance().get_pixbuf()->save(filePath, "png");
}

void ImageDialog::open_image()
{
    dialog->signal_response().connect(
        sigc::bind(
            sigc::ptr_fun(open_image_callback),
            this->dialog));

    dialog->show();
}

void ImageDialog::export_image()
{
    dialog->set_current_name("untitled.png");

    dialog->signal_response().connect(
        sigc::bind(
            sigc::ptr_fun(export_image_callback),
            this->dialog));

    dialog->show();
}