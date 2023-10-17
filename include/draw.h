#pragma once
#include "board.h"
#include "color.h"
#include <stdint.h>

#define CELL_WIDTH 24
#define CELL_HEIGHT 24
#define EDGE_WIDTH 2
#define BOARD_TOP_MARGIN 48
#define BOARD_LEFT_MARGIN 128
#define TITLE_TOP_MARGIN 24
#define TITLE_LEFT_MARGIN 176

#define DIGIT_SEGMENT_WIDTH 2
#define DIGIT_TOP_MARGIN 4
#define DIGIT_LEFT_MARGIN 7
#define DIGIT_HORIZONTAL_LENGTH 10
#define DIGIT_VERTICAL_LENGTH 16
#define DIGIT_VERTICAL_LENGTH_HALF 8

enum CellType {
  kEmpty,
  kDigit,
  kCharacter,
  kPotato,
  kFlag,
};

void draw_board(struct Board *b);
void draw_digit(int x, int y, int number, enum ColorType color);
void draw_digit_segment(int x, int y, int segment, enum ColorType color);