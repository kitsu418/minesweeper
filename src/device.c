#include "device.h"

void set_vram(int x, int y, uint8_t color) {
  VRAM_DATA_ADDR[x * VRAM_WIDTH + y] = color;
}

void commit_vram() { *VRAM_COMMIT_ADDR = 1; }

bool keyboard_ready() { return *KEYBOARD_READY_ADDR; }

uint8_t keyboard_data() { return *KEYBOARD_DATA_ADDR; }