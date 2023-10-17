#include "draw.h"
#include "graphics.h"

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
  graphics_fill_rectangle(x * CELL_WIDTH, y * CELL_HEIGHT, CELL_WIDTH,
                          CELL_HEIGHT, color);
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