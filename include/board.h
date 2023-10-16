#pragma once
#include <stdbool.h>
#include <stdint.h>

#ifdef EASY
#define WIDTH 9
#define HEIGHT 9
#elif NORMAL
#define WIDTH 16
#define HEIGHT 16
#elif HARD
#define WIDTH 16
#define HEIGHT 30
#endif

enum CellState {
  kUnopen,
  kNumbered,
  kBlank,
  kFlagged,
  kMine,
};

struct Board {
  enum CellState state[HEIGHT][WIDTH];
  uint8_t number[HEIGHT][WIDTH];
  bool mine[HEIGHT][WIDTH];
  uint8_t width;
  uint8_t height;
  bool failed;
  // position of the cursor
  uint8_t x;
  uint8_t y;
};

static inline bool check_in_board(struct Board *b, uint8_t x, uint8_t y) {
  return (x < b->height) && (y < b->width);
}

void init_board(struct Board *b);
void clear_board(struct Board *b);
void drop_board(struct Board *b);
void generate_mine(struct Board *b, int mine_num);
void move_cursor_up(struct Board *b);
void move_cursor_down(struct Board *b);
void move_cursor_left(struct Board *b);
void move_cursor_right(struct Board *b);
void first_click_with_mine(struct Board *b, uint8_t x, uint8_t y);
void flag_cell(struct Board *b);
void click_cell(struct Board *b);
void uncover_cell(struct Board *b, uint8_t x, uint8_t y);
uint8_t count_surrounding_mines(struct Board *b, uint8_t x, uint8_t y);