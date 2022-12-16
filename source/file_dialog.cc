#include "file_dialog.h"
#include <gtkmm/dialog.h>

FileDialog::FileDialog(Gtk::Window *parent)
{
    this->dialog = Gtk::FileChooserNative::create("", Gtk::FileChooser::Action::OPEN, "Accept", "Cancel");
    
    this->dialog->set_modal(true);
    this->dialog->set_transient_for(*parent);

    this->set_filter();
}

void FileDialog::emit_signal_based_on_response(int response)
{
    this->dialog->hide();

    if (response != Gtk::ResponseType::ACCEPT)
        return;

    this->signalDialogSuccess.emit(
        this->dialog->get_file()->get_path(), 
        this->dialog->get_action());
}

void FileDialog::set_filter()
{
    auto filterImages = Gtk::FileFilter::create();
    filterImages->set_name("JPG Files");
    filterImages->add_mime_type("image/jpeg");
    filterImages->add_mime_type("image/png");

    this->dialog->set_filter(filterImages);
}

void FileDialog::open_file_dialog()
{
    this->dialog->set_title("Open Image");
    this->dialog->set_action(Gtk::FileChooser::Action::OPEN);

    this->dialog->signal_response().connect(sigc::mem_fun(*this, &FileDialog::emit_signal_based_on_response));

    this->dialog->show();
}

void FileDialog::export_file_dialog()
{
    this->dialog->set_title("Export Image");
    this->dialog->set_action(Gtk::FileChooser::Action::SAVE);
    this->dialog->set_current_name("untitled.jpg");

    this->dialog->signal_response().connect(sigc::mem_fun(*this, &FileDialog::emit_signal_based_on_response));

    this->dialog->show();
}

sigc::signal<void(std::string, Gtk::FileChooser::Action)> FileDialog::signal_dialog_success()
{
    return this->signalDialogSuccess;
}
