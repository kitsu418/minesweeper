#pragma once
#include "color.h"
#include <stdint.h>

void graphics_init();
void graphics_sync();
void graphics_draw_rectangle(int x, int y, int w, int h, enum ColorType color);
void graphics_fill_rectangle(int x, int y, int w, int h, enum ColorType color);
void graphics_draw_line(int x1, int y1, int x2, int y2, enum ColorType color);
void graphics_draw_pixel(int x, int y, enum ColorType color);