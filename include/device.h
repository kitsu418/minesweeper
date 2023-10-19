#pragma once
#include "display.h"
#include <stdbool.h>
#include <stdint.h>

// How to use devices like a ps2 keyboard or a VGA monitor?
// My choice is using MMIO (Memory-mapped I/O), which means using the same
// address space to address both main memory[a] and I/O devices.

// As for VGA monitors, all I need to do is to write data of each pixel into
// vram, then commit it.
#define VRAM_DATA_ADDR ((volatile uint8_t *)0xdeadbeec)
#define VRAM_COMMIT_ADDR ((volatile bool *)0xdeadbeed)
#define VRAM_WIDTH DISPLAY_WIDTH
#define VRAM_HEIGHT DISPLAY_HEIGHT

// As for ps2 keyboards, the interface has two main signal lines, data and
// clock. To transmit a byte, the device simply outputs a serial frame of data
// (including 8 bits of data and a parity bit) on the Data line serially as it
// toggles the Clock line once for each bit.
// The driver would maintain a FIFO queue to store received bytes and a ready
// signal.
#define KEYBOARD_READY_ADDR ((volatile bool *)0xdeadbeee)
#define KEYBOARD_DATA_ADDR ((volatile uint8_t *)0xdeadbeef)

#define SCANCODE_Q 0x15
#define SCANCODE_W 0x1D
#define SCANCODE_A 0x1C
#define SCANCODE_S 0x1B
#define SCANCODE_D 0x23
#define SCANCODE_F 0x2B
#define SCANCODE_O 0x44
#define SCANCODE_V 0x2A
#define SCANCODE_R 0x2D

void set_vram(int x, int y, uint8_t color);
void commit_vram();

bool keyboard_ready();
uint8_t keyboard_data();