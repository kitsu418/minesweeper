#include "draw.h"
#include "color.h"
#include "graphics.h"
#include <stdint.h>

// x and y are locations of the cell's upper left corner
//       1
//    ------
//   |      |
// 2 |   3  | 4
//   |------|
// 5 |      | 6
//   |      |
//    ------
//       7
void draw_digit_segment(int x, int y, int segment, enum ColorType color) {
  switch (segment) {
  case 1:
    graphics_fill_rectangle(x + DIGIT_TOP_MARGIN, y + DIGIT_LEFT_MARGIN,
                            DIGIT_HORIZONTAL_LENGTH, DIGIT_SEGMENT_WIDTH,
                            color);
    break;
  case 2:
    graphics_fill_rectangle(x + DIGIT_TOP_MARGIN, y + DIGIT_LEFT_MARGIN,
                            DIGIT_SEGMENT_WIDTH, DIGIT_VERTICAL_LENGTH_HALF,
                            color);
    break;
  case 3:
    graphics_fill_rectangle(x + DIGIT_TOP_MARGIN + DIGIT_VERTICAL_LENGTH_HALF -
                                (DIGIT_SEGMENT_WIDTH >> 1),
                            y + DIGIT_LEFT_MARGIN, DIGIT_HORIZONTAL_LENGTH,
                            DIGIT_SEGMENT_WIDTH, color);
    break;
  case 4:
    graphics_fill_rectangle(
        x + DIGIT_TOP_MARGIN,
        y + DIGIT_LEFT_MARGIN + DIGIT_HORIZONTAL_LENGTH - DIGIT_SEGMENT_WIDTH,
        DIGIT_SEGMENT_WIDTH, DIGIT_VERTICAL_LENGTH_HALF, color);
    break;
  case 5:
    graphics_fill_rectangle(x + DIGIT_TOP_MARGIN + DIGIT_VERTICAL_LENGTH_HALF,
                            y + DIGIT_LEFT_MARGIN, DIGIT_SEGMENT_WIDTH,
                            DIGIT_VERTICAL_LENGTH_HALF, color);
    break;
  case 6:
    graphics_fill_rectangle(
        x + DIGIT_TOP_MARGIN + DIGIT_VERTICAL_LENGTH_HALF,
        y + DIGIT_LEFT_MARGIN + DIGIT_HORIZONTAL_LENGTH - DIGIT_SEGMENT_WIDTH,
        DIGIT_SEGMENT_WIDTH, DIGIT_VERTICAL_LENGTH_HALF, color);
    break;
  case 7:
    graphics_fill_rectangle(x + DIGIT_TOP_MARGIN + DIGIT_VERTICAL_LENGTH -
                                DIGIT_SEGMENT_WIDTH,
                            y + DIGIT_LEFT_MARGIN, DIGIT_HORIZONTAL_LENGTH,
                            DIGIT_SEGMENT_WIDTH, color);
    break;
  }
}

void draw_digit(int x, int y, int number, enum ColorType color) {
  number %= 10;
  switch (number) {
  case 0:
    draw_digit_segment(x, y, 1, color);
    draw_digit_segment(x, y, 2, color);
    draw_digit_segment(x, y, 4, color);
    draw_digit_segment(x, y, 5, color);
    draw_digit_segment(x, y, 6, color);
    draw_digit_segment(x, y, 7, color);
    break;
  case 1:
    draw_digit_segment(x, y, 4, color);
    draw_digit_segment(x, y, 6, color);
    break;
  case 2:
    draw_digit_segment(x, y, 1, color);
    draw_digit_segment(x, y, 3, color);
    draw_digit_segment(x, y, 4, color);
    draw_digit_segment(x, y, 5, color);
    draw_digit_segment(x, y, 7, color);
    break;
  case 3:
    draw_digit_segment(x, y, 1, color);
    draw_digit_segment(x, y, 3, color);
    draw_digit_segment(x, y, 4, color);
    draw_digit_segment(x, y, 6, color);
    draw_digit_segment(x, y, 7, color);
    break;
  case 4:
    draw_digit_segment(x, y, 2, color);
    draw_digit_segment(x, y, 3, color);
    draw_digit_segment(x, y, 4, color);
    draw_digit_segment(x, y, 6, color);
    break;
  case 5:
    draw_digit_segment(x, y, 1, color);
    draw_digit_segment(x, y, 2, color);
    draw_digit_segment(x, y, 3, color);
    draw_digit_segment(x, y, 6, color);
    draw_digit_segment(x, y, 7, color);
    break;
  case 6:
    draw_digit_segment(x, y, 1, color);
    draw_digit_segment(x, y, 2, color);
    draw_digit_segment(x, y, 3, color);
    draw_digit_segment(x, y, 5, color);
    draw_digit_segment(x, y, 6, color);
    draw_digit_segment(x, y, 7, color);
    break;
  case 7:
    draw_digit_segment(x, y, 1, color);
    draw_digit_segment(x, y, 4, color);
    draw_digit_segment(x, y, 6, color);
    break;
  case 8:
    draw_digit_segment(x, y, 1, color);
    draw_digit_segment(x, y, 2, color);
    draw_digit_segment(x, y, 3, color);
    draw_digit_segment(x, y, 4, color);
    draw_digit_segment(x, y, 5, color);
    draw_digit_segment(x, y, 6, color);
    draw_digit_segment(x, y, 7, color);
    break;
  case 9:
    draw_digit_segment(x, y, 1, color);
    draw_digit_segment(x, y, 2, color);
    draw_digit_segment(x, y, 3, color);
    draw_digit_segment(x, y, 4, color);
    draw_digit_segment(x, y, 6, color);
    draw_digit_segment(x, y, 7, color);
    break;
  }
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
  draw_character(x, y, 'M', color);
  draw_character(x, y + CELL_WIDTH, 'I', color);
  draw_character(x, y + 2 * CELL_WIDTH, 'N', color);
  draw_character(x, y + 3 * CELL_WIDTH, 'E', color);
  draw_character(x, y + 4 * CELL_WIDTH, 'S', color);
  draw_character(x, y + 5 * CELL_WIDTH, 'W', color);
  draw_character(x, y + 6 * CELL_WIDTH, 'E', color);
  draw_character(x, y + 7 * CELL_WIDTH, 'E', color);
  draw_character(x, y + 8 * CELL_WIDTH, 'P', color);
  draw_character(x, y + 9 * CELL_WIDTH, 'E', color);
  draw_character(x, y + 10 * CELL_WIDTH, 'R', color);
  draw_character(x, y + 11 * CELL_WIDTH, '!', color);
}

void draw_character(int x, int y, char c, enum ColorType color) {
  switch (c) {
  case 'A':
    break;
  case 'B':
    break;
  case 'C':
    break;
  case 'D':
    break;
  case 'E':
    //  ------
    // |
    // |------
    // |
    //  ------
    graphics_draw_line(x + 2, y + 2, x + 22, y + 2, color);
    graphics_draw_line(x + 2, y + 2, x + 2, y + 22, color);
    graphics_draw_line(x + 12, y + 2, x + 12, y + 22, color);
    graphics_draw_line(x + 22, y + 2, x + 22, y + 22, color);
    break;
  case 'F':
    break;
  case 'G':
    break;
  case 'H':
    break;
  case 'I':
    // ---
    //  |
    //  |
    //  |
    // ---
    graphics_draw_line(x + 2, y + 7, x + 2, y + 17, color);
    graphics_draw_line(x + 2, y + 12, x + 22, y + 12, color);
    graphics_draw_line(x + 22, y + 7, x + 22, y + 17, color);
    break;
  case 'J':
    break;
  case 'K':
    break;
  case 'L':
    break;
  case 'M':
    // |\    /|
    // | \  / |
    // |  \/  |
    graphics_draw_line(x + 2, y + 2, x + 22, y + 2, color);
    graphics_draw_line(x + 2, y + 2, x + 22, y + 12, color);
    graphics_draw_line(x + 2, y + 22, x + 22, y + 12, color);
    graphics_draw_line(x + 2, y + 22, x + 22, y + 22, color);
    break;
  case 'N':
    // |\_   |
    // |  \_ |
    // |    \|
    graphics_draw_line(x + 2, y + 2, x + 22, y + 2, color);
    graphics_draw_line(x + 2, y + 2, x + 22, y + 22, color);
    graphics_draw_line(x + 2, y + 22, x + 22, y + 22, color);
    break;
  case 'O':
    break;
  case 'P':
    //  ------
    // |      |
    // |------
    // |
    // |
    graphics_draw_line(x + 2, y + 2, x + 22, y + 2, color);
    graphics_draw_line(x + 2, y + 2, x + 2, y + 22, color);
    graphics_draw_line(x + 12, y + 2, x + 12, y + 22, color);
    graphics_draw_line(x + 2, y + 22, x + 12, y + 22, color);
    break;
  case 'Q':
    break;
  case 'R':
    //  ------
    // |      |
    // |------
    // |\_
    // |  \_
    // |    \_
    graphics_draw_line(x + 2, y + 2, x + 22, y + 2, color);
    graphics_draw_line(x + 2, y + 2, x + 2, y + 22, color);
    graphics_draw_line(x + 12, y + 2, x + 12, y + 22, color);
    graphics_draw_line(x + 2, y + 22, x + 12, y + 22, color);
    graphics_draw_line(x + 12, y + 2, x + 22, y + 22, color);
    break;
  case 'S':
    //  ------
    // |
    //  ------
    //        |
    //  ------
    graphics_draw_line(x + 2, y + 2, x + 12, y + 2, color);
    graphics_draw_line(x + 12, y + 22, x + 22, y + 22, color);
    graphics_draw_line(x + 2, y + 2, x + 2, y + 22, color);
    graphics_draw_line(x + 12, y + 2, x + 12, y + 22, color);
    graphics_draw_line(x + 22, y + 2, x + 22, y + 22, color);
    break;
  case 'T':
    break;
  case 'U':
    break;
  case 'V':
    break;
  case 'W':
    // |  /\  |
    // | /  \ |
    // |/    \|
    graphics_draw_line(x + 2, y + 2, x + 22, y + 2, color);
    graphics_draw_line(x + 22, y + 2, x + 2, y + 12, color);
    graphics_draw_line(x + 22, y + 22, x + 2, y + 12, color);
    graphics_draw_line(x + 2, y + 22, x + 22, y + 22, color);
    break;
  case 'X':
    break;
  case 'Y':
    break;
  case 'Z':
    break;
  case '!':
    //  -
    // | |
    // | |
    // | |
    // | |
    //  -
    //
    //  -
    // | |
    //  -
    graphics_draw_line(x + 2, y + 12, x + 18, y + 12, color);
    graphics_draw_line(x + 20, y + 12, x + 22, y + 12, color);
    break;
  }
}

void draw_mine(int x, int y) {
  draw_character(x, y, 'M', kTitleColor);
}

void draw_blank_cell(int x, int y, enum ColorType color) {
  graphics_fill_rectangle(x + 1, y + 1, CELL_WIDTH - 2, CELL_HEIGHT - 2, kBlankCellColor);
}

void draw_board(struct Board *b) {
  draw_title(TITLE_TOP_MARGIN, TITLE_LEFT_MARGIN, kTitleColor);
  for (uint8_t i = 0; i < b->height; ++i) {
    for (uint8_t j = 0; j < b->width; ++j) {
      int x = BOARD_TOP_MARGIN + i * CELL_HEIGHT;
      int y = BOARD_LEFT_MARGIN + j * CELL_WIDTH;
      draw_cell_background(x, y, kBackgroundColor);
      draw_cell_frame(x, y, (b->x == i && b->y == j) ? kCursorColor : kFrameColor);
      switch (b->state[i][j]) {
      case kUnopen:
        break;
      case kNumbered:
        draw_digit(x, y, b->number[i][j], kDigitSegmentColor);
        break;
      case kBlank:
        draw_blank_cell(x, y, kBlankCellColor);
        break;
      case kFlagged:
        draw_flag(x, y);
        break;
      case kMine:
        draw_mine(x, y);
        break;
      }
    }
  }
  graphics_sync();
}