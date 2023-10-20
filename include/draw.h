#pragma once
#include "board.h"
#include "color.h"
#include <stdint.h>

#define CELL_WIDTH 24
#define CELL_HEIGHT 24
#define EDGE_WIDTH 2
#define BOARD_TOP_MARGIN 48
#define BOARD_LEFT_MARGIN 20
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

#define MESSAGE_TOP_MARGIN (BOARD_TOP_MARGIN + BOARD_HEIGHT * CELL_HEIGHT + 16)

#define INFO_WINDOW_FRAME_LEFT_MARGIN (BOARD_LEFT_MARGIN + BOARD_WIDTH * CELL_WIDTH + 14)
#define INFO_WINDOW_LEFT_MARGIN (INFO_WINDOW_FRAME_LEFT_MARGIN + 7)
#define INFO_WINDOW_WIDTH 192
#define INFO_WINDOW_ROW_SPACING 5
#define INFO_WINDOW_ROW_NUM 3
#define INFO_WINDOW_HEIGHT (INFO_WINDOW_ROW_NUM * (CHAR_HEIGHT + INFO_WINDOW_ROW_SPACING))
#define INFO_WINDOW_FRAME_HEIGHT (INFO_WINDOW_HEIGHT + 4 + INFO_WINDOW_ROW_SPACING)
#define INFO_WINDOW_FRAME_WIDTH (INFO_WINDOW_WIDTH + 14)
#define INFO_WINDOW_FRAME_TOP_MARGIN 60
#define INFO_WINDOW_TOP_MARGIN (INFO_WINDOW_FRAME_TOP_MARGIN + 2 + INFO_WINDOW_ROW_SPACING)
#define INFO_WINDOW_NUMBER_LEFT_MARGIN (INFO_WINDOW_LEFT_MARGIN + 11 * CHAR_WIDTH)

#define SANAE_TOP_MARGIN (INFO_WINDOW_TOP_MARGIN + INFO_WINDOW_FRAME_HEIGHT + 80)
#define SANAE_LEFT_MARGIN (INFO_WINDOW_FRAME_LEFT_MARGIN)

#define RESTART_BUTTON_TOP_MARGIN (INFO_WINDOW_TOP_MARGIN + INFO_WINDOW_FRAME_HEIGHT + 30)
#define RESTART_BUTTON_LEFT_MARGIN (INFO_WINDOW_FRAME_LEFT_MARGIN)
#define RESTART_BUTTON_WIDTH 120
#define RESTART_BUTTON_HEIGHT (CHAR_HEIGHT + 10)
#define RESTART_CHAR_WIDTH 96
#define RESTART_CHAR_TOP_MARGIN (RESTART_BUTTON_TOP_MARGIN + 5)
#define RESTART_CHAR_LEFT_MARGIN (RESTART_BUTTON_LEFT_MARGIN + (RESTART_BUTTON_WIDTH - RESTART_CHAR_WIDTH) / 2)
#define EXIT_BUTTON_TOP_MARGIN RESTART_BUTTON_TOP_MARGIN
#define EXIT_BUTTON_LEFT_MARGIN (RESTART_BUTTON_LEFT_MARGIN + RESTART_BUTTON_WIDTH + 10)
#define EXIT_BUTTON_WIDTH 76
#define EXIT_BUTTON_HEIGHT RESTART_BUTTON_HEIGHT
#define EXIT_CHAR_WIDTH 64
#define EXIT_CHAR_TOP_MARGIN RESTART_CHAR_TOP_MARGIN
#define EXIT_CHAR_LEFT_MARGIN (EXIT_BUTTON_LEFT_MARGIN + (EXIT_BUTTON_WIDTH - EXIT_CHAR_WIDTH) / 2)

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
void draw_cell_frame(int x, int y, int w, enum ColorType color);
void draw_cell_background(int x, int y, enum ColorType color);
void draw_flag(int x, int y);
void draw_title(int x, int y, enum ColorType color);
void draw_character(int x, int y, char c, enum ColorType color);
void draw_string(int x, int y, char str[], int length, enum ColorType color);
void draw_mine(int x, int y);
void draw_blank_cell(int x, int y, enum ColorType color);
void clear_message();
void draw_info_window(struct Board *b);
void clear_info_window();
void draw_sanae(struct Board *b);
void draw_exit_button();
void draw_restart_button();