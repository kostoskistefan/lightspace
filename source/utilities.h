#ifndef UTILITIES_H
#define UTILITIES_H

#include <gtkmm.h>

double fastPow(double a, double b);

double string_to_double(const Glib::ustring &str);
bool string_to_bool(const Glib::ustring &str);

void trim(Glib::ustring &s);
std::vector<Glib::ustring> split(Glib::ustring &str, char delimeter);

#endif