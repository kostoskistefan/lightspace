#include "signal_handler.h"
#include "ui_builder.h"
#include "gui.h"

SignalHandler &SignalHandler::get_instance()
{
    static SignalHandler instance;
    return instance;
}

SignalHandler::SignalHandler()
{
    initialize_keyboard_handler();
    initialize_signals();
}

void SignalHandler::initialize_signals()
{
    auto textView = GUI::get_instance().get_effects_text_view();

    auto applyEffectsButton = GUI::get_instance().get_apply_effects_button();
    
    textView->get_buffer()->signal_changed().connect([=]{
        applyEffectsButton->set_sensitive(
            !textView->get_buffer()->get_text().empty()); });
}

bool on_key_pressed(guint keyval, guint, Gdk::ModifierType state)
{
    switch (keyval)
    {
    case GDK_KEY_bracketright:
        GUI::get_instance().toggle_dual_view();
        break;
    case GDK_KEY_backslash:
        GUI::get_instance().toggle_before_after();
        break;
    }

    return true;
}

void SignalHandler::initialize_keyboard_handler()
{
    auto controller = Gtk::EventControllerKey::create();

    controller->signal_key_pressed().connect(
        sigc::ptr_fun(on_key_pressed), false);

    GUI::get_instance().get_main_window()->add_controller(controller);
}