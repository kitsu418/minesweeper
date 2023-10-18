#include "board.h"
#include "display.h"
#include "draw.h"
#include "graphics.h"
#include "sdl_interface.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>

int main() {
  struct Board board;
  init_board(&board);
  generate_mine(&board, MINE_NUM);
  graphics_init();

  bool alive = true;
#ifndef RISCV
  SDL_Event event;
  while (alive) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        alive = false;
      } else {
        if (event.type == SDL_KEYDOWN) {
          if (board.failed == false) {
            switch (event.key.keysym.sym) {
            case SDLK_w:
              move_cursor_up(&board);
              break;
            case SDLK_s:
              move_cursor_down(&board);
              break;
            case SDLK_a:
              move_cursor_left(&board);
              break;
            case SDLK_d:
              move_cursor_right(&board);
              break;
            case SDLK_f:
              flag_cell(&board);
              break;
            case SDLK_o:
              click_cell(&board);
              break;
            case SDLK_r:
              clear_board(&board);
              generate_mine(&board, MINE_NUM);
              break;
            case SDLK_q:
              alive = false;
              break;
            case SDLK_v:
              board.god_mode ^= 1;
              break;
            }
          } else {
            if (event.key.keysym.sym == SDLK_r) {
              clear_board(&board);
              generate_mine(&board, MINE_NUM);
            } else if (event.key.keysym.sym == SDLK_q) {
              alive = false;
            }
          }
        }
      }
    }
    draw_board(&board);
    graphics_sync();
  }
  sdl_drop();
#else
  while (alive) {
    // command = getchar();
    if (board.failed == false) {
      switch (command) {
      case 'w':
        move_cursor_up(&board);
        break;
      case 'a':
        move_cursor_left(&board);
        break;
      case 's':
        move_cursor_down(&board);
        break;
      case 'd':
        move_cursor_right(&board);
        break;
      case 'f':
        flag_cell(&board);
        break;
      case 'o':
        click_cell(&board);
        break;
      case 'r':
        clear_board(&board);
        break;
      }
    } else {
      if (command == 'r') {
        clear_board(&board);
      }
    }
    draw_board(&board);
  }
#endif
  return 0;
}