#include "graphics.h"
#include "board.h"
#include "color.h"
#include "device.h"
#include "display.h"
#include <stdint.h>

#ifndef RISCV
#include "sdl_interface.h"

uint8_t vmem[DISPLAY_SIZE];
#endif

void graphics_sync() {
#ifdef RISCV
  commit_vram();
#else
  sdl_sync();
#endif
}

void graphics_init(int x, int y) {
#ifndef RISCV
  sdl_init();
#endif
  for (int i = 0; i < DISPLAY_HEIGHT; ++i) {
    for (int j = 0; j < DISPLAY_WIDTH; ++j) {
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
#ifdef RISCV
  set_vram(x, y, color);
#else
  vram[idx(x, y)] = color;
#endif
}

#define abs(x) ((x) >= 0 ? (x) : -(x))

void graphics_draw_line(int x1, int y1, int x2, int y2, enum ColorType color) {
  int dx = abs(x2 - x1);
  int dy = abs(y2 - y1);
  int sx = (x1 < x2) ? 1 : -1;
  int sy = (y1 < y2) ? 1 : -1;
  int err = dx - dy;

  while (1) {
    graphics_draw_pixel(x1, y1, color);

    if (x1 == x2 && y1 == y2) {
      break;
    }

    int e2 = 2 * err;

    if (e2 > -dy) {
      err -= dy;
      x1 += sx;
    }

    if (e2 < dx) {
      err += dx;
      y1 += sy;
    }
  }
}