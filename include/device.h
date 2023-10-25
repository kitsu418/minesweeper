#pragma once
#include "display.h"
#include <stdbool.h>
#include <stdint.h>

// How to use devices like a ps2 keyboard or a VGA monitor?
// My choice is using MMIO (Memory-mapped I/O), which means using the same
// address space to address both main memory[a] and I/O devices.

// As for VGA monitors, all I need to do is to write data of each pixel into
// vram, then commit it.
// #define VRAM_DATA_ADDR ((volatile uint8_t *)0xdeadbeec)
// #define VRAM_COMMIT_ADDR ((volatile bool *)0xdeadbeed)
#define VRAM_DATA_ADDR ((volatile uint8_t *)0xdeadbef5)
#define VRAM_COMMIT_ADDR ((volatile bool *)0xdeadbef4)
#define VRAM_WIDTH DISPLAY_WIDTH
#define VRAM_HEIGHT DISPLAY_HEIGHT

void set_vram(int x, int y, uint8_t color);
void commit_vram();

// As for ps2 mouses, the higher level interface would give us the x, y position
// and butten presses directly.
#define MOUSE_X ((volatile uint16_t *)0xdeadbeef)
#define MOUSE_Y ((volatile uint16_t *)0xdeadbef0)
#define MOUSE_LEFT_BUTTON ((volatile bool *)0xdeadbef1)
#define MOUSE_MIDDLE_BUTTON ((volatile bool *)0xdeadbef2)
#define MOUSE_RIGHT_BUTTON ((volatile bool *)0xdeadbef3)

bool mouse_left_button_pressed();
bool mouse_middle_button_pressed();
bool mouse_right_button_pressed();
uint16_t mouse_x();
uint16_t mouse_y();
