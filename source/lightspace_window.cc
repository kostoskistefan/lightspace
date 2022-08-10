#include "lightspace_window.h"
#include "utilities.h"
#include "parsers/effects_parser.h"

LightspaceWindow::LightspaceWindow(
	BaseObjectType *cobject,
	const std::shared_ptr<Gtk::Builder> &builder)
	: Gtk::ApplicationWindow(cobject), builder(builder)
{
	this->imageProcessor = new ImageProcessor();

	this->imageView = builder->get_widget<Gtk::Picture>("image_view");
	this->originalImageView = builder->get_widget<Gtk::Picture>("original_image_view");

	this->beforeLabel = builder->get_widget<Gtk::Label>("before_label");
	this->afterLabel = builder->get_widget<Gtk::Label>("after_label");

	this->effectsTextView = builder->get_widget<Gtk::TextView>("effects_text_view");

	this->applyEffectsButton = builder->get_widget<Gtk::Button>("apply_effects_button");
	this->toggleDualViewButton = builder->get_widget<Gtk::ToggleButton>("toggle_dual_view_button");
	this->toggleBeforeAfterButton = builder->get_widget<Gtk::ToggleButton>("toggle_before_after_button");

	map_signals();
}

void LightspaceWindow::on_file_dialog_success(std::string filePath, Gtk::FileChooser::Action action)
{
	if (action == Gtk::FileChooser::Action::OPEN)
	{
		auto pixbuf = Gdk::Pixbuf::create_from_file(filePath);

		this->imageProcessor->open_image(pixbuf);

		this->originalImageView->set_pixbuf(pixbuf);
		redraw_image();

		this->set_title_from_filepath(filePath);
	}

	else if (action == Gtk::FileChooser::Action::SAVE)
	{
		this->imageProcessor->save_image(filePath, "jpeg");
	}
}

void LightspaceWindow::map_signals()
{
	auto app = Gtk::Application::get_default();

	FileDialog *fileDialog = new FileDialog(this);

	app->add_action("open_image", sigc::mem_fun(*fileDialog, &FileDialog::open_file_dialog));
	app->add_action("export_image", sigc::mem_fun(*fileDialog, &FileDialog::export_file_dialog));
	app->add_action("toggle_dual_view", sigc::mem_fun(*this, &LightspaceWindow::toggle_dual_view));
	app->add_action("toggle_before_after", sigc::mem_fun(*this, &LightspaceWindow::toggle_before_after));

	fileDialog->signal_dialog_success().connect(
		sigc::mem_fun(*this, &LightspaceWindow::on_file_dialog_success));

	this->effectsTextView->get_buffer()->signal_changed().connect(
		sigc::mem_fun(*this, &LightspaceWindow::on_effects_text_view_changed));

	this->applyEffectsButton->signal_clicked().connect(
		sigc::mem_fun(*this, &LightspaceWindow::on_apply_effects_button_clicked));

	// TODO: Move key press controller to a separate function.
	auto controller = Gtk::EventControllerKey::create();

	controller->signal_key_pressed().connect(
		sigc::mem_fun(*this, &LightspaceWindow::on_key_pressed), false);

	this->add_controller(controller);
}

void LightspaceWindow::on_effects_text_view_changed()
{
	bool textViewHasText = this->effectsTextView->get_buffer()->get_text().empty();

	this->applyEffectsButton->set_sensitive(!textViewHasText);
}

void LightspaceWindow::redraw_image()
{
	this->imageView->set_pixbuf(this->imageProcessor->get_processed_pixbuf());
}

void LightspaceWindow::toggle_dual_view()
{
	auto currentState = !this->toggleDualViewButton->get_active();

	this->originalImageView->set_visible(currentState);
	this->beforeLabel->set_visible(currentState);
	this->afterLabel->set_visible(currentState);

	this->toggleDualViewButton->set_active(currentState);
}

void LightspaceWindow::toggle_before_after()
{
	auto currentState = !this->toggleBeforeAfterButton->get_active();

	if (currentState)
		this->imageView->set_pixbuf(this->imageProcessor->copy_original_pixbuf());

	else
		this->imageView->set_pixbuf(this->imageProcessor->get_processed_pixbuf());

	this->toggleBeforeAfterButton->set_active(currentState);
}

void LightspaceWindow::set_title_from_filepath(const std::string &path)
{
	this->set_title(Utilities::get_filename_from_path(path) + " - Lightspace");
}

bool LightspaceWindow::on_key_pressed(guint keyval, guint, Gdk::ModifierType state)
{
	(void) state;

	switch (keyval)
	{
	case GDK_KEY_bracketright:
		this->toggle_dual_view();
		break;
	case GDK_KEY_backslash:
		this->toggle_before_after();
		break;
	}

	return true;
}

void LightspaceWindow::on_apply_effects_button_clicked()
{
	auto text = this->effectsTextView->get_buffer()->get_text();
	auto effects = EffectsParser::parse(text);
	this->imageProcessor->process_image(effects);
	this->redraw_image();
}

std::unique_ptr<LightspaceWindow> LightspaceWindow::create()
{
	// Parse a resource file containing a GtkBuilder UI definition.
	auto builder = Gtk::Builder::create_from_resource("/com/github/kostoskistefan/lightspace/lightspace.ui");

	// Get ApplicationWindow that is specified in the UI file but
	// implemented in our code. So our ApplicationWindow is derived.
	LightspaceWindow *window = Gtk::Builder::get_widget_derived<LightspaceWindow>(builder, "window");

	if (!window)
		throw std::runtime_error("Failed to acquire the main window from lightspace.ui");

	return std::unique_ptr<LightspaceWindow>(window);
}
