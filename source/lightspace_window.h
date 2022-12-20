#ifndef LIGHTSPACE_WINDOW_H
#define LIGHTSPACE_WINDOW_H

#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>
#include <gtkmm/builder.h>
#include <gtkmm/picture.h>
#include <gtkmm/textview.h>
#include <gtkmm/togglebutton.h>
#include <gtkmm/applicationwindow.h>
#include "file_dialog.h"
#include "image_processor.h"
#include "widgets/histogram.h"

/**
 * @class LightspaceWindow
 * @brief The main window of the application.
 */
class LightspaceWindow : public Gtk::ApplicationWindow
{
public:
	/**
	 * @brief Constructor.
	 * @param cobject Pointer to the underlying C type of the base class.
	 * @param refBuilder The GtkBuilder object.
	 * @note Due to convention of using Gtk::Builder::get_widget_derived()
	 * constructor of the class should look like this. You can read 
	 * more about it in the reference.
	 */
	LightspaceWindow(
		BaseObjectType *cobject,
		const std::shared_ptr<Gtk::Builder> &builder);

	/**
	 * @brief Create a LightspaceWindow from a ui file.
	 * @return The window.
	 */
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

	/**
	 * @brief Map all the signals in the application that are connected with the main window.
	 */
	void map_signals();

	/**
	 * @brief Load the custom css style sheet.
	 */
	void load_style_sheet();

	/**
	 * @brief Toggle between single and dual view.
	 * @details If the dual view is enabled, the image view is split into two,
	 * where the left one shows the original, unaltered image, and the right 
	 * one shows the processed image.
	 */
	void toggle_dual_view();

	/**
	 * @brief Toggle between showing the original image and the processed image.
	 */
	void toggle_before_after();

	/**
	 * @brief Set the title of the window based on the opened image.
	 */
	void set_title_from_filepath(const std::string &path);

	/**
	 * @brief Callback method to handle the "apply" effects button click.
	 */
	void on_apply_effects_button_clicked();

	/**
	 * @brief Callback method to handle keyboard events.
	 * @param keyval The value of the pressed key.
	 * @param keycode The raw code of the pressed key.
	 * @param state The bitmask, representing the state of modifier keys and pointer buttons.
	 * @return True if the event was handled, false otherwise.
	 */
	bool on_key_pressed(uint keyval, uint keycode, Gdk::ModifierType state);

	/**
	 * @brief Callback method to handle the "open" or "save" dialog results.
	 * @param filePath The path to the file.
	 * @param action The action that was performed (either OPEN or SAVE).
	 */
	void on_file_dialog_success(std::string filePath, Gtk::FileChooser::Action action);

	/**
	 * @brief Creates and sets up a key press listener
	 * @details Creates an EventControllerKey and connects the callback method to the
	 * LightspaceWindow::on_key_pressed method
	 */
	void setup_keymap();
};

#endif // LIGHTSPACE_WINDOW_H
