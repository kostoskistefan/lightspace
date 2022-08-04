#ifndef EFFECT_H
#define EFFECT_H

#include <gtkmm.h>

void apply_temperature(double value);
void apply_tint(double value);
void apply_exposure(double value);
void apply_contrast(double value);
void apply_saturation(double value);

void apply_grayscale(bool value);

#endif