#ifndef GUI_H
#define GUI_H

#include <gtkmm.h>

class GUI
{
public:
    static GUI &get_instance();

    void set_initial_widget_sensitivity();

    Gtk::Window   *get_main_window();
    Gtk::TextView *get_effects_text_view();
    Gtk::Button   *get_apply_effects_button();
    Gtk::Button   *get_export_image_button();

    void load_css();
    void load_dark_theme();

    void set_picture();
    void redraw_picture();
    void toggle_dual_view();
    void toggle_before_after();

private:
    GUI();
    GUI(GUI const &);
    void operator=(GUI const &);

    Gtk::Window *window;

    Gtk::Picture *imageView;
    Gtk::Picture *originalImageView;
    bool is_original_image_shown;

    Gtk::TextView *effectsTextView;

    Gtk::Label *beforeLabel;
    Gtk::Label *afterLabel;

    Gtk::Button *applyEffectsButton;
    Gtk::Button *exportImageButton;
    Gtk::ToggleButton *dualViewToggleButton;
    Gtk::ToggleButton *beforeAfterToggleButton;
};

#endif // GUI_H