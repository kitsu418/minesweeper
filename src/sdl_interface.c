#include "sdl_interface.h"
#include "color.h"
#include "display.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#define MAX_TEXT 100

SDL_Window *window;
SDL_Renderer *renderer;

static int get_color(enum ColorType color) {
  switch (color) {
  case kBackgroundColor:
    return COLOR_BACKGROUND;
  case kDigitSegmentColor:
    return COLOR_CYAN;
  case kBoomCellBackgroundColor:
    return COLOR_RED;
  case kTitleColor:
    return COLOR_CYAN;
  case kFlagColor:
    return COLOR_RED;
  case kFlagpoleColor:
    return COLOR_BLACK;
  case kFrameColor:
    return COLOR_BLACK;
  case kCursorColor:
    return COLOR_ORANGE;
  case kBlankCellColor:
    return COLOR_GRAY;
  }
  return -1;
}

void sdl_init() {
  if (SDL_Init(SDL_INIT_VIDEO) == -1) {
  }
  if (SDL_CreateWindowAndRenderer(DISPLAY_WIDTH, DISPLAY_HEIGHT, 0, &window,
                                  &renderer) == -1) {
  }
  SDL_SetWindowTitle(window, "Minesweeper");
}

void sdl_set_color(unsigned int color) {
  SDL_SetRenderDrawColor(renderer, color >> 24, color >> 16, color >> 8, color);
}

void sdl_draw_rectangle(int x, int y, int w, int h) {
  SDL_Rect rect = {x, y, w, h};
  SDL_RenderDrawRect(renderer, &rect);
}

void sdl_fill_rectangle(int x, int y, int w, int h) {
  SDL_Rect rect = {x, y, w, h};
  SDL_RenderFillRect(renderer, &rect);
}

void sdl_draw_line(int x1, int y1, int x2, int y2) {
  SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void sdl_sync() {
  for (int i = 0; i < DISPLAY_HEIGHT; i++) {
    for (int j = 0; j < DISPLAY_WIDTH; j++) {
      int c = get_color(vram[idx(i, j)]);
      sdl_set_color(c);
      SDL_RenderDrawPoint(renderer, j, i);
    }
  }
  SDL_RenderPresent(renderer);
}

void sdl_drop() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}