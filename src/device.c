#include "device.h"

extern unsigned __stacktop;
// initial stack pointer is first address of program
__attribute__((section(".stack"), used)) unsigned* __stack_init = &__stacktop;

extern int main();

__attribute__((section(".text.start"))) __attribute__((naked)) void _start() {
  asm("mv sp, %0\n\t" ::"r"(&__stacktop));
  asm("j %0\n\t" ::"i"(&main));
}

void set_vram(int x, int y, uint8_t color) {
  VRAM_DATA_ADDR[x * VRAM_WIDTH + y] = color;
}

void commit_vram() { *VRAM_COMMIT_ADDR = 1; }

bool mouse_left_button_pressed() { return *MOUSE_LEFT_BUTTON; }
bool mouse_middle_button_pressed() { return *MOUSE_MIDDLE_BUTTON; }
bool mouse_right_button_pressed() { return *MOUSE_RIGHT_BUTTON; }
uint16_t mouse_x() { return *MOUSE_X; }
uint16_t mouse_y() { return *MOUSE_Y; };
