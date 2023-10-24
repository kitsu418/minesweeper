#include "graphics.h"
#include "board.h"
#include "color.h"
#include "display.h"
#include <stdint.h>

#ifndef RISCV
#include "sdl_interface.h"
uint8_t vram_mem[DISPLAY_SIZE / MAP_PIXEL_WIDTH / MAP_PIXEL_HEIGHT];
#else
#include "device.h"
#endif

void graphics_sync() {
#ifdef RISCV
  commit_vram();
#else
  sdl_sync();
#endif
}

void graphics_init() {
#ifndef RISCV
  sdl_init();
  vram = (uint8_t *)vram_mem;
#endif
  for (int i = 0; i < DISPLAY_HEIGHT / MAP_PIXEL_HEIGHT; ++i) {
    for (int j = 0; j < DISPLAY_WIDTH / MAP_PIXEL_WIDTH; ++j) {
#ifdef RISCV
      set_vram(i, j, kBackgroundColor);
#else
      vram[idx(i, j)] = kBackgroundColor;
#endif
    }
  }
  graphics_sync();
}

void graphics_draw_rectangle(int x, int y, int w, int h, enum ColorType color) {
  x /= MAP_PIXEL_HEIGHT;
  h /= MAP_PIXEL_HEIGHT;
  y /= MAP_PIXEL_WIDTH;
  w /= MAP_PIXEL_WIDTH;
  for (int i = 0; i < w; ++i) {
#ifdef RISCV
    set_vram(x, y + i, color);
    set_vram(x + h - 1, y + i, color);
#else
    vram[idx(x, y + i)] = color;
    vram[idx(x + h - 1, y + i)] = color;
#endif
  }

  for (int i = 0; i < h; ++i) {
#ifdef RISCV
    set_vram(x + i, y, color);
    set_vram(x + i, y + w - 1, color);
#else
    vram[idx(x + i, y)] = color;
    vram[idx(x + i, y + w - 1)] = color;
#endif
  }
}

void graphics_fill_rectangle(int x, int y, int w, int h, enum ColorType color) {
  x /= MAP_PIXEL_HEIGHT;
  h /= MAP_PIXEL_HEIGHT;
  y /= MAP_PIXEL_WIDTH;
  w /= MAP_PIXEL_WIDTH;
  for (int i = x; i < x + h; ++i) {
    for (int j = y; j < y + w; ++j) {
#ifdef RISCV
      set_vram(i, j, color);
#else
      vram[idx(i, j)] = color;
#endif
    }
  }
}

void graphics_draw_pixel(int x, int y, enum ColorType color) {
  x /= MAP_PIXEL_HEIGHT;
  y /= MAP_PIXEL_WIDTH;
#ifdef RISCV
  set_vram(x, y, color);
#else
  vram[idx(x, y)] = color;
#endif
}