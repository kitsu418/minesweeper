#pragma once
#include <stdint.h>

#define DISPLAY_WIDTH 640
#define DISPLAY_HEIGHT 480
#define DISPLAY_SIZE (DISPLAY_WIDTH * DISPLAY_HEIGHT)
#define idx(x, y) ((x)*DISPLAY_WIDTH + (y))

extern uint8_t *vram;