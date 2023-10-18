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
#define TITLE_LEFT_MARGIN 224

#define DIGIT_SEGMENT_WIDTH 2
#define DIGIT_TOP_MARGIN 5
#define DIGIT_LEFT_MARGIN 6
#define DIGIT_HORIZONTAL_LENGTH 10
#define DIGIT_VERTICAL_LENGTH 16
#define DIGIT_VERTICAL_LENGTH_HALF 8

#define FLAGPOLE_TOP_MARGIN 4
#define FLAGPOLE_LEFT_MARGIN 6
#define FLAGPOLE_HEIGHT 16
#define FLAGPOLE_WIDTH 2
#define FLAG_TOP_MARGIN 4
#define FLAG_LEFT_MARGIN (FLAGPOLE_LEFT_MARGIN + FLAGPOLE_WIDTH)
#define FLAG_HEIGHT 6
#define FLAG_WIDTH 10

#define MINE_TOP_MARGIN 4
#define MINE_LEFT_MARGIN 4

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
void draw_cell_frame(int x, int y, enum ColorType color);
void draw_cell_background(int x, int y, enum ColorType color);
void draw_flag(int x, int y);
void draw_title(int x, int y, enum ColorType color);
void draw_character(int x, int y, char c, enum ColorType color);
void draw_string(int x, int y, char str[], int length, enum ColorType color);
void draw_mine(int x, int y);
void draw_blank_cell(int x, int y, enum ColorType color);