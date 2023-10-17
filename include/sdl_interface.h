#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#define COLOR_BACKGROUND 0xefefdfff
#define COLOR_RED 0xef6f4fff
#define COLOR_GREEN 0x6fcf5fff
#define COLOR_CYAN 0x4fafdfff
#define COLOR_YELLOW 0xffdf3fff
#define COLOR_PURPLE 0xbf5fafff
#define COLOR_ORANGE 0xef9f3fff
#define COLOR_WHITE 0xFFFFFFFF
#define COLOR_GRAY 0xAAAAAAFF
#define COLOR_BLACK 0

extern SDL_Window *window;
extern SDL_Renderer *renderer;

void sdl_sync();
void sdl_init();
void sdl_drop();