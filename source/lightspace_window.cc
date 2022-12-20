#include "lightspace_window.h"
#include "utilities.h"
#include "parsers/effects_parser.h"
#include <gtkmm/cssprovider.h>
#include <gtkmm/eventcontrollerkey.h>

LightspaceWindow::LightspaceWindow(
		BaseObjectType *cobject,
		const std::shared_ptr<Gtk::Builder> &builder)
	: Gtk::ApplicationWindow(cobject), builder(builder)
{
	this->imageProcessor = new ImageProcessor();
	this->histogram = new Histogram();

	this->imageView = builder->get_widget<Gtk::Picture>("image_view");
	this->originalImageView = builder->get_widget<Gtk::Picture>("original_image_view");

	this->beforeLabel = builder->get_widget<Gtk::Label>("before_label");
	this->afterLabel = builder->get_widget<Gtk::Label>("after_label");

	this->effectsTextView = builder->get_widget<Gtk::TextView>("effects_text_view");

	this->applyEffectsButton = builder->get_widget<Gtk::Button>("apply_effects_button");
	this->toggleDualViewButton = builder->get_widget<Gtk::ToggleButton>("toggle_dual_view_button");
	this->toggleBeforeAfterButton = builder->get_widget<Gtk::ToggleButton>("toggle_before_after_button");

	this->histogramBox = builder->get_widget<Gtk::Box>("histogram_box");
	this->histogramBox->insert_child_at_start(*this->histogram);

	map_signals();
	setup_keymap();
	load_style_sheet();
}

void LightspaceWindow::load_style_sheet()
{
	auto provider = Gtk::CssProvider::create();
	provider->load_from_resource("/com/github/kostoskistefan/lightspace/lightspace.css");

	this->get_style_context()->add_provider_for_display(
			this->get_display(), provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
}

void LightspaceWindow::map_signals()
{
	auto app = Gtk::Application::get_default();

	FileDialog *fileDialog = new FileDialog(this);

	app->add_action("open_image", sigc::mem_fun(*fileDialog, &FileDialog::open_file_dialog));
	app->add_action("export_image", sigc::mem_fun(*fileDialog, &FileDialog::export_file_dialog));
	app->add_action("toggle_dual_view", sigc::mem_fun(*this, &LightspaceWindow::toggle_dual_view));
	app->add_action("toggle_before_after", sigc::mem_fun(*this, &LightspaceWindow::toggle_before_after));
	app->add_action("apply_effects", sigc::mem_fun(*this, &LightspaceWindow::on_apply_effects_button_clicked));

	fileDialog->signal_dialog_success().connect(
			sigc::mem_fun(*this, &LightspaceWindow::on_file_dialog_success));

	this->imageProcessor->signal_processing_changed().connect(
			sigc::mem_fun(*this->histogram, &Histogram::queue_draw));
}

void LightspaceWindow::setup_keymap()
{
	auto controller = Gtk::EventControllerKey::create();

	controller->signal_key_pressed().connect(
			sigc::mem_fun(*this, &LightspaceWindow::on_key_pressed), false);

	this->add_controller(controller);
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

	std::shared_ptr<Gdk::Pixbuf> currentlyVisiblePixbuf = nullptr;

	if (currentState)
		currentlyVisiblePixbuf = this->imageProcessor->copy_original_pixbuf();

	else
		currentlyVisiblePixbuf = this->imageProcessor->get_processed_pixbuf();

	this->imageView->set_pixbuf(currentlyVisiblePixbuf);
	this->histogram->set_pixbuf(currentlyVisiblePixbuf);
	this->histogram->queue_draw();

	this->toggleBeforeAfterButton->set_active(currentState);
}

void LightspaceWindow::set_title_from_filepath(const std::string &path)
{
	this->set_title(Utilities::get_filename_from_path(path) + " - Lightspace");
}

void LightspaceWindow::on_file_dialog_success(std::string filePath, Gtk::FileChooser::Action action)
{
	if (action == Gtk::FileChooser::Action::OPEN)
	{
		auto pixbuf = Gdk::Pixbuf::create_from_file(filePath);

		this->imageProcessor->open_image(pixbuf);

		this->imageView->set_pixbuf(this->imageProcessor->get_processed_pixbuf());
		this->originalImageView->set_pixbuf(this->imageProcessor->copy_original_pixbuf());

		this->set_title_from_filepath(filePath);

		this->histogram->set_pixbuf(this->imageProcessor->get_processed_pixbuf());
		this->histogram->queue_draw();
	}

	else if (action == Gtk::FileChooser::Action::SAVE)
		this->imageProcessor->save_image(filePath, "jpeg");
}

bool LightspaceWindow::on_key_pressed(uint keyval, uint, Gdk::ModifierType state)
{
	(void)state;

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

	if (!this->toggleBeforeAfterButton->get_active())
		this->imageView->set_pixbuf(this->imageProcessor->get_processed_pixbuf());
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
