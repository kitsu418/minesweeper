#include "sdl_interface.h"
#include "color.h"
#include "display.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_render.h>
#include <stdint.h>

#define MAX_TEXT 100

SDL_Window *window;
SDL_Renderer *renderer;

static uint32_t get_color(enum ColorType color) {
  switch (color) {
  case kBackgroundColor:
    return COLOR_BACKGROUND;
  case kBoomCellBackgroundColor:
    return COLOR_BOOM_BACKGROUND;
  case kTitleColor:
    return COLOR_TITLE;
  case kFlagColor:
    return COLOR_FLAG;
  case kFlagpoleColor:
    return COLOR_FLAGPOLE;
  case kFrameColor:
    return COLOR_FRAME;
  case kCursorColor:
    return COLOR_CURSOR;
  case kBlankCellColor:
  case kOpenedBackgroundColor:
    return COLOR_OPENED;
  case kUnopenedBackgroundColor:
    return COLOR_UNOPENED;
  case kCharacterColor:
    return COLOR_CHARACTER;
  case kMineColor:
    return COLOR_MINE;
  case kMessageColor:
    return COLOR_MESSAGE;
  case kSanaeColor0:
    return COLOR_SANAE_0;
  case kSanaeColor1:
    return COLOR_SANAE_1;
  case kSanaeColor2:
    return COLOR_SANAE_2;
  case kSanaeColor3:
    return COLOR_SANAE_3;
  case kSanaeColor4:
    return COLOR_SANAE_4;
  case kSanaeColor5:
    return COLOR_SANAE_5;
  case kSanaeColor6:
    return COLOR_SANAE_6;
  case kSanaeColor7:
    return COLOR_SANAE_7;
  case kSanaeColor8:
    return COLOR_SANAE_8;
  case kSanaeColor9:
    return COLOR_SANAE_9;
  case kSanaeColor10:
    return COLOR_SANAE_10;
  case kSanaeColor11:
    return COLOR_SANAE_11;
  case kSanaeColor12:
    return COLOR_SANAE_12;
  case kSanaeColor13:
    return COLOR_SANAE_13;
  case kSanaeColor14:
    return COLOR_SANAE_14;
  case kSanaeColor15:
    return COLOR_SANAE_15;
  case kSanaeColor16:
    return COLOR_SANAE_16;
  case kSanaeColor17:
    return COLOR_SANAE_17;
  case kSanaeColor18:
    return COLOR_SANAE_18;
  }
  return -1;
}

#define EXEC(expression)                                                       \
  if ((expression) != 0) {                                                     \
    fprintf(stderr, "%s\n", SDL_GetError());                                   \
  }

void sdl_init() {
  EXEC(SDL_Init(SDL_INIT_VIDEO));
  window = SDL_CreateWindow("Minesweeper", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, DISPLAY_WIDTH,
                            DISPLAY_HEIGHT, SDL_WINDOW_OPENGL);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void sdl_set_color(uint32_t color) {
  EXEC(SDL_SetRenderDrawColor(renderer, color >> 24, color >> 16, color >> 8,
                              color));
}

void sdl_draw_rectangle(int x, int y, int w, int h) {
  SDL_Rect rect = {x, y, w, h};
  EXEC(SDL_RenderDrawRect(renderer, &rect));
}

void sdl_fill_rectangle(int x, int y, int w, int h) {
  SDL_Rect rect = {x, y, w, h};
  EXEC(SDL_RenderFillRect(renderer, &rect));
}

void sdl_sync() {
  for (int i = 0; i < DISPLAY_HEIGHT; i++) {
    for (int j = 0; j < DISPLAY_WIDTH; j++) {
      uint32_t c = get_color(vram[idx(i, j)]);
      sdl_set_color(c);
      EXEC(SDL_RenderDrawPoint(renderer, j, i));
    }
  }
  SDL_RenderPresent(renderer);
}

void sdl_drop() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}