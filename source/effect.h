#ifndef EFFECT_H
#define EFFECT_H

#include <gtkmm.h>
#include "image_processor.h"

void apply_temperature(double value);
void apply_tint(double value);
void apply_exposure(double value);
void apply_contrast(double value);

#endif