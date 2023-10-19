#include "board.h"
#include "display.h"
#include "draw.h"
#include "graphics.h"

#ifndef RISCV
#include "sdl_interface.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#else
#include "device.h"
#endif

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
          if (event.key.keysym.sym == SDLK_r) {
            clear_board(&board);
            clear_message();
            generate_mine(&board, MINE_NUM);
          } else if (event.key.keysym.sym == SDLK_q) {
            alive = false;
          } else if (board.failed == false && board.unlocked_num < SUCCESS) {
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
            case SDLK_v:
              board.god_mode ^= 1;
              break;
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
    while (!keyboard_ready()) {
      uint8_t key = keyboard_data();
      if (key == SCANCODE_R) {
        clear_board(&board);
        clear_message();
        generate_mine(&board, MINE_NUM);
      } else if (key == SCANCODE_Q) {
        alive = false;
      } else if (board.failed == false && board.unlocked_num < SUCCESS) {
        switch (keyboard_data()) {
        case SCANCODE_W:
          move_cursor_up(&board);
          break;
        case SCANCODE_S:
          move_cursor_down(&board);
          break;
        case SCANCODE_A:
          move_cursor_left(&board);
          break;
        case SCANCODE_D:
          move_cursor_right(&board);
          break;
        case SCANCODE_F:
          flag_cell(&board);
          break;
        case SCANCODE_O:
          click_cell(&board);
          break;
        case SCANCODE_V:
          board.god_mode ^= 1;
          break;
        }
      } else {
      }
    }
    draw_board(&board);
    graphics_sync();
  }
#endif
  return 0;
}