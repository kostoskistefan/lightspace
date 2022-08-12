#ifndef LIGHTSPACE_WINDOW_H
#define LIGHTSPACE_WINDOW_H

#include <gtkmm.h>
#include "file_dialog.h"
#include "image_processor.h"
#include "widgets/histogram.h"

class LightspaceWindow : public Gtk::ApplicationWindow
{
public:
	// Due to convention of using Gtk::Builder::get_widget_derived()
	// constructor of the class should look like this. You can read
	// more about it in the reference.
	LightspaceWindow(
		BaseObjectType *cobject,
		const std::shared_ptr<Gtk::Builder> &builder);

	static std::unique_ptr<LightspaceWindow> create();

private:
    Histogram *histogram;
	ImageProcessor *imageProcessor;

	std::shared_ptr<Gtk::Builder> builder;

	Gtk::Picture *imageView;
	Gtk::Picture *originalImageView;

	Gtk::Label *beforeLabel;
	Gtk::Label *afterLabel;

    Gtk::Box *histogramBox;

	Gtk::Button *applyEffectsButton;
	Gtk::ToggleButton *toggleDualViewButton;
	Gtk::ToggleButton *toggleBeforeAfterButton;

	Gtk::TextView *effectsTextView;

	void map_signals();
	void load_style_sheet();
	void toggle_dual_view();
	void toggle_before_after();
	void set_title_from_filepath(const std::string &path);

	void on_effects_text_view_changed();
	void on_apply_effects_button_clicked();
	bool on_key_pressed(guint keyval, guint, Gdk::ModifierType state);

	void on_file_dialog_success(std::string filePath, Gtk::FileChooser::Action action);
};

#endif // LIGHTSPACE_WINDOW_H
