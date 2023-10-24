#pragma once
#include <stdbool.h>
#include <stdint.h>

#define BOARD_WIDTH 16
#define BOARD_HEIGHT 16
#define MINE_NUM 40
#define SUCCESS (BOARD_WIDTH * BOARD_HEIGHT - MINE_NUM)

enum CellState {
  kUnopen,
  kNumbered,
  kBlank,
  kFlagged,
  kMine,
};

struct Board {
  enum CellState state[BOARD_HEIGHT][BOARD_WIDTH];
  uint8_t number[BOARD_HEIGHT][BOARD_WIDTH];
  bool mine[BOARD_HEIGHT][BOARD_WIDTH];
  uint8_t width;
  uint8_t height;
  bool failed;
  bool is_first_click;
  bool god_mode;
  uint8_t unlocked_num;
  uint8_t flagged_num;
  // position of the cursor
  uint8_t x;
  uint8_t y;
};

void init_board(struct Board *b);
void clear_board(struct Board *b);
void drop_board(struct Board *b);
void generate_mine(struct Board *b, int mine_num);
void first_click_with_mine(struct Board *b, int x, int y);
void flag_cell(struct Board *b);
void click_cell(struct Board *b);
void uncover_cell(struct Board *b, int x, int y);
uint8_t count_surrounding_mines(struct Board *b, int x, int y);
void set_cursor(struct Board *b, uint16_t x, uint16_t y);
bool mouse_in_board(struct Board *b, uint16_t x, uint16_t y);