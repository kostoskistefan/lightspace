#include "signal_handler.h"
#include "ui_builder.h"
#include "image_processor.h"

SignalHandler &SignalHandler::get_instance()
{
    static SignalHandler instance;
    return instance;
}

SignalHandler::SignalHandler()
{
    this->window = UIBuilder::get_instance()
                     .get_widget<Gtk::Window>("appWindow");

    initialize_keyboard_handler();
    initialize_signals();
}

void on_textView_text_changed(Gtk::TextView *textView, Gtk::Button *applyEffectsButton)
{
    applyEffectsButton->set_sensitive(!textView->get_buffer()->get_text().empty());
}

void SignalHandler::initialize_signals()
{
    auto textView = UIBuilder::get_instance()
                        .get_widget<Gtk::TextView>("textView");

    auto applyEffectsButton = UIBuilder::get_instance()
                                  .get_widget<Gtk::Button>("applyEffectsButton");

    textView->get_buffer()->signal_changed().connect(
        sigc::bind(
            sigc::ptr_fun(on_textView_text_changed),
            textView,
            applyEffectsButton));
}

bool on_key_pressed(guint keyval, guint, Gdk::ModifierType state)
{
    switch (keyval)
    {
    case GDK_KEY_Tab:
        ImageProcessor::get_instance().toggle_dual_view();
        break;
    case GDK_KEY_backslash:
        ImageProcessor::get_instance().toggle_before_after();
        break;
    }

    return true;
}

void SignalHandler::initialize_keyboard_handler()
{
    auto controller = Gtk::EventControllerKey::create();

    controller->signal_key_pressed().connect(
        sigc::ptr_fun(on_key_pressed), false);

    this->window->add_controller(controller);
}