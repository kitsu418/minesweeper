#pragma once
#include "color.h"
#include <stdint.h>

void graphics_init(int x, int y);
void graphics_sync();
void graphics_draw_rectangle(int x, int y, int w, int h, enum ColorType color);
void graphics_fill_rectangle(int x, int y, int w, int h, enum ColorType color);