#pragma once
#include <stdint.h>

#ifdef SMALL_MEMORY
#define MAP_PIXEL_WIDTH 2
#define MAP_PIXEL_HEIGHT 2
#else
#define MAP_PIXEL_WIDTH 1
#define MAP_PIXEL_HEIGHT 1
#endif
#define DISPLAY_WIDTH 640
#define DISPLAY_HEIGHT 480
#define DISPLAY_SIZE (DISPLAY_WIDTH * DISPLAY_HEIGHT)
#define idx(x, y) ((x) * (DISPLAY_WIDTH / MAP_PIXEL_WIDTH) + (y))

extern uint8_t *vram;