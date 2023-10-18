#include "draw.h"
#include "color.h"
#include "font16x16.h"
#include "graphics.h"
#include <stdint.h>

void draw_digit(int x, int y, int number, enum ColorType color) {
  number %= 10;
  draw_character(x + DIGIT_TOP_MARGIN, y + DIGIT_LEFT_MARGIN, number + '0',
                 color);
}

void draw_cell_frame(int x, int y, enum ColorType color) {
  graphics_draw_rectangle(x, y, CELL_WIDTH, CELL_HEIGHT, color);
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

void draw_board(struct Board *b) {
  draw_title(TITLE_TOP_MARGIN, TITLE_LEFT_MARGIN, kTitleColor);
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
      draw_cell_frame(x, y,
                      (b->x == i && b->y == j) ? kCursorColor : kFrameColor);
    }
  }
  graphics_sync();
}