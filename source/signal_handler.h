#ifndef SIGNAL_HANDLER_H
#define SIGNAL_HANDLER_H

#include <gtkmm.h>

class SignalHandler 
{
public:
    static SignalHandler &get_instance();

private:
    SignalHandler();
    SignalHandler(SignalHandler const &);
    void operator=(SignalHandler const &);

    Gtk::Window *window;
    
    void initialize_signals();
    void initialize_keyboard_handler();
};

#endif // SIGNAL_HANDLER_H