#include "board.h"
#include "display.h"
#include "draw.h"
#include "graphics.h"
#include "mouse.h"
#include <stdint.h>

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
  draw_init(&board);

  bool alive = true;
  uint16_t x = 0;
  uint16_t y = 0;
  bool lb = false;
  bool mb = false;
  bool rb = false;
  while (alive) {
#ifndef RISCV
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        alive = false;
      } else if (event.type == SDL_MOUSEMOTION) {
        x = event.motion.y;
        y = event.motion.x;
        draw_cursor(&board, x, y);
      } else if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (exit_button_activated(x, y)) {
          alive = false;
        } else if (restart_button_activated(x, y)) {
          clear_board(&board);
          clear_message();
          generate_mine(&board, MINE_NUM);
          draw_init(&board);
        } else if (board.failed == false && board.unlocked_num < SUCCESS) {
          if (event.button.button == SDL_BUTTON_LEFT) {
            click_cell(&board);
          }
          if (event.button.button == SDL_BUTTON_RIGHT) {
            flag_cell(&board);
          }
          if (event.button.button == SDL_BUTTON_MIDDLE) {
            god_mode(&board);
          }
        }
      }
    }
#else
    x = mouse_y();
    y = mouse_x();
    lb = mouse_left_button_pressed();
    mb = mouse_middle_button_pressed();
    rb = mouse_right_button_pressed();
    draw_cursor(&board, x, y);
    if (lb || mb || rb) {
      if (exit_button_activated(x, y)) {
        alive = false;
      } else if (restart_button_activated(x, y)) {
        clear_board(&board);
        clear_message();
        generate_mine(&board, MINE_NUM);
        draw_init(&board);
      } else if (board.failed == false && board.unlocked_num < SUCCESS) {
        if (lb) {
          click_cell(&board);
        }
        if (rb) {
          flag_cell(&board);
        }
        if (mb) {
          god_mode(&board);
        }
      }
    }
#endif
    draw_board(&board);
    graphics_sync();
  }

#ifndef RISCV
  sdl_drop();
#endif
  return 0;
}