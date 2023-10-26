#include "draw.h"
#include "board.h"
#include "color.h"
#include "font16x16.h"
#include "graphics.h"
#include "sanae.h"
#include <stdint.h>

void draw_digit(int x, int y, int number, enum ColorType color) {
  number %= 10;
  draw_character(x + DIGIT_TOP_MARGIN, y + DIGIT_LEFT_MARGIN, number + '0',
                 color);
}

void draw_cell_frame(int x, int y, int w, enum ColorType color) {
  for (int i = 0; i < w; ++i) {
    graphics_draw_rectangle(x + i, y + i, CELL_WIDTH - i * 2,
                            CELL_HEIGHT - i * 2, color);
  }
}

void draw_cell_background(int x, int y, enum ColorType color) {
  graphics_fill_rectangle(x, y, CELL_WIDTH, CELL_HEIGHT, color);
}

void draw_flag(int x, int y) {
  graphics_fill_rectangle(x + FLAGPOLE_TOP_MARGIN, y + FLAGPOLE_LEFT_MARGIN,
                          FLAGPOLE_WIDTH, FLAGPOLE_HEIGHT, kFlagpoleColor);
  graphics_fill_rectangle(x + FLAG_TOP_MARGIN, y + FLAG_LEFT_MARGIN, FLAG_WIDTH,
                          FLAG_HEIGHT, kFlagColor);
}

void draw_title(int x, int y, enum ColorType color) {
  draw_string(x, y, "MINESWEEPER!", 12, color);
}

// character size: 14x16
void draw_character(int x, int y, char c, enum ColorType color) {
  uint8_t index = get_font_index(c);
  for (int i = 0; i < CHAR_HEIGHT; ++i) {
    uint32_t mask = 0x8000;
    for (int j = 0; j < CHAR_WIDTH; ++j, mask >>= 1) {
      if (font[index][i] & mask) {
        graphics_draw_pixel(x + i, y + j, color);
      }
    }
  }
}

void draw_string(int x, int y, char str[], int length, enum ColorType color) {
  for (int i = 0; i < length; ++i) {
    draw_character(x, y + i * CHAR_WIDTH, str[i], color);
  }
}

inline static void draw_string_in_middle(int x, char str[], int length,
                                         enum ColorType color) {
  draw_string(x, (DISPLAY_WIDTH - length * CHAR_WIDTH) >> 1, str, length,
              color);
}

void draw_mine(int x, int y) {
  for (int i = 0; i < MINE_HEIGHT; ++i) {
    uint32_t mask = 0x8000;
    for (int j = 0; j < MINE_WIDTH; ++j, mask >>= 1) {
      if (mine_font[i] & mask) {
        graphics_draw_pixel(x + i + MINE_TOP_MARGIN, y + j + MINE_LEFT_MARGIN,
                            kMineColor);
      }
    }
  }
}

void draw_blank_cell(int x, int y, enum ColorType color) {
  graphics_fill_rectangle(x + 1, y + 1, CELL_WIDTH - 2, CELL_HEIGHT - 2,
                          kBlankCellColor);
}

void draw_board(struct Board *b, int16_t mouse_x, int16_t mouse_y) {
  for (int i = 0; i < DISPLAY_HEIGHT; ++i) {
    for (int j = 0; j < DISPLAY_WIDTH; ++j) {
      graphics_draw_pixel(i, j, kBackgroundColor);
    }
  }
  draw_title(TITLE_TOP_MARGIN, TITLE_LEFT_MARGIN, kTitleColor);
  draw_sanae(b);
  draw_exit_button();
  draw_restart_button();
  for (uint8_t i = 0; i < b->height; ++i) {
    for (uint8_t j = 0; j < b->width; ++j) {
      int x = BOARD_TOP_MARGIN + i * CELL_HEIGHT;
      int y = BOARD_LEFT_MARGIN + j * CELL_WIDTH;
      switch (b->state[i][j]) {
      case kUnopen:
        draw_cell_background(x, y, kUnopenedBackgroundColor);
        if (b->god_mode) {
          if (b->mine[i][j]) {
            draw_mine(x, y);
          }
        }
        break;
      case kNumbered:
        draw_cell_background(x, y, kOpenedBackgroundColor);
        draw_digit(x, y, b->number[i][j], kCharacterColor);
        break;
      case kBlank:
        draw_cell_background(x, y, kOpenedBackgroundColor);
        draw_blank_cell(x, y, kBlankCellColor);
        break;
      case kFlagged:
        draw_cell_background(x, y, kUnopenedBackgroundColor);
        draw_flag(x, y);
        break;
      case kMine:
        draw_cell_background(x, y, kBoomCellBackgroundColor);
        draw_mine(x, y);
        break;
      }
      if (b->x == i && b->y == j && mouse_in_board(b, mouse_x, mouse_y)) {
        draw_cell_frame(x, y, 2, kCursorColor);
      } else {
        draw_cell_frame(x, y, 1, kFrameColor);
      }
    }
  }
  if (b->unlocked_num == SUCCESS) {
    draw_string_in_middle(MESSAGE_TOP_MARGIN, "YOU WIN!", 8, kMessageColor);
  } else if (b->failed) {
    draw_string_in_middle(MESSAGE_TOP_MARGIN, "MINE TRIGGERED, RESTART PLEASE",
                          30, kMessageColor);
  }
  clear_info_window();
  draw_info_window(b);
}

inline static void draw_number_rtol(int x, int y, int num,
                                    enum ColorType color) {
  do {
    draw_character(x, y, num % 10 + '0', color);
    y -= CHAR_WIDTH;
    num /= 10;
  } while (num);
}

void clear_message() {
  for (int i = MESSAGE_TOP_MARGIN; i < MESSAGE_TOP_MARGIN + CHAR_HEIGHT; ++i) {
    for (int j = 0; j < DISPLAY_WIDTH; ++j) {
      graphics_draw_pixel(i, j, kBackgroundColor);
    }
  }
}

void draw_info_window(struct Board *b) {
  // draw the frame
  graphics_draw_rectangle(
      INFO_WINDOW_FRAME_TOP_MARGIN, INFO_WINDOW_FRAME_LEFT_MARGIN,
      INFO_WINDOW_FRAME_WIDTH, INFO_WINDOW_FRAME_HEIGHT, kFrameColor);
  graphics_draw_rectangle(
      INFO_WINDOW_FRAME_TOP_MARGIN + 1, INFO_WINDOW_FRAME_LEFT_MARGIN + 1,
      INFO_WINDOW_FRAME_WIDTH - 2, INFO_WINDOW_FRAME_HEIGHT - 2, kFrameColor);
  draw_string(INFO_WINDOW_TOP_MARGIN, INFO_WINDOW_LEFT_MARGIN, "UNLOCKED ", 9,
              kMessageColor);
  draw_number_rtol(INFO_WINDOW_TOP_MARGIN, INFO_WINDOW_NUMBER_LEFT_MARGIN,
                   b->unlocked_num, kMessageColor);
  draw_string(INFO_WINDOW_TOP_MARGIN + CHAR_HEIGHT + INFO_WINDOW_ROW_SPACING,
              INFO_WINDOW_LEFT_MARGIN, "FLAGGED  ", 9, kMessageColor);
  draw_number_rtol(
      INFO_WINDOW_TOP_MARGIN + CHAR_HEIGHT + INFO_WINDOW_ROW_SPACING,
      INFO_WINDOW_NUMBER_LEFT_MARGIN, b->flagged_num, kMessageColor);
  draw_string(INFO_WINDOW_TOP_MARGIN + CHAR_HEIGHT * 2 +
                  INFO_WINDOW_ROW_SPACING * 2,
              INFO_WINDOW_LEFT_MARGIN, "REMAINING", 9, kMessageColor);
  draw_number_rtol(
      INFO_WINDOW_TOP_MARGIN + CHAR_HEIGHT * 2 + INFO_WINDOW_ROW_SPACING * 2,
      INFO_WINDOW_NUMBER_LEFT_MARGIN, MINE_NUM - b->flagged_num, kMessageColor);
}

void clear_info_window() {
  for (int i = INFO_WINDOW_FRAME_TOP_MARGIN;
       i < INFO_WINDOW_FRAME_TOP_MARGIN + INFO_WINDOW_FRAME_HEIGHT; ++i) {
    for (int j = INFO_WINDOW_FRAME_LEFT_MARGIN;
         j < INFO_WINDOW_FRAME_LEFT_MARGIN + INFO_WINDOW_FRAME_WIDTH; ++j) {
      graphics_draw_pixel(i, j, kBackgroundColor);
    }
  }
}

void draw_sanae(struct Board *b) {
  for (int i = 0; i < SANAE_HEIGHT; ++i) {
    for (int j = 0; j < SANAE_WIDTH; ++j) {
      if (b->failed) {
        graphics_fill_rectangle(i * 6 + SANAE_TOP_MARGIN,
                                j * 6 + SANAE_LEFT_MARGIN, 6, 6,
                                sanae_failed[i * SANAE_WIDTH + j]);

      } else if (b->unlocked_num == SUCCESS) {
        graphics_fill_rectangle(i * 6 + SANAE_TOP_MARGIN,
                                j * 6 + SANAE_LEFT_MARGIN, 6, 6,
                                sanae_successful[i * SANAE_WIDTH + j]);

      } else {
        graphics_fill_rectangle(i * 6 + SANAE_TOP_MARGIN,
                                j * 6 + SANAE_LEFT_MARGIN, 6, 6,
                                sanae[i * SANAE_WIDTH + j]);
      }
    }
  }
}

void draw_exit_button() {
  graphics_draw_rectangle(EXIT_BUTTON_TOP_MARGIN, EXIT_BUTTON_LEFT_MARGIN,
                          EXIT_BUTTON_WIDTH, EXIT_BUTTON_HEIGHT, kFrameColor);
  graphics_draw_rectangle(EXIT_BUTTON_TOP_MARGIN + 1,
                          EXIT_BUTTON_LEFT_MARGIN + 1, EXIT_BUTTON_WIDTH - 2,
                          EXIT_BUTTON_HEIGHT - 2, kFrameColor);
  draw_string(EXIT_CHAR_TOP_MARGIN, EXIT_CHAR_LEFT_MARGIN, "EXIT", 4,
              kMessageColor);
}

void draw_restart_button() {
  graphics_draw_rectangle(RESTART_BUTTON_TOP_MARGIN, RESTART_BUTTON_LEFT_MARGIN,
                          RESTART_BUTTON_WIDTH, RESTART_BUTTON_HEIGHT,
                          kFrameColor);
  graphics_draw_rectangle(
      RESTART_BUTTON_TOP_MARGIN + 1, RESTART_BUTTON_LEFT_MARGIN + 1,
      RESTART_BUTTON_WIDTH - 2, RESTART_BUTTON_HEIGHT - 2, kFrameColor);
  draw_string(RESTART_CHAR_TOP_MARGIN, RESTART_CHAR_LEFT_MARGIN, "REMAKE", 6,
              kMessageColor);
}