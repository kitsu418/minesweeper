#include "board.h"
#include "color.h"
#include "draw.h"
#include "random.h"
#include <stdbool.h>
#include <stdint.h>

static inline bool check_in_board(struct Board *b, int x, int y) {
  return (x < b->height && x >= 0) && (y < b->width && y >= 0);
}

void init_board(struct Board *b) {
  b->height = BOARD_HEIGHT;
  b->width = BOARD_WIDTH;
  b->x = 0;
  b->y = 0;
  clear_board(b);
}

void clear_board(struct Board *b) {
  b->failed = false;
  b->is_first_click = true;
  b->god_mode = false;
  b->unlocked_num = 0;
  b->flagged_num = 0;
  for (int i = 0; i < b->height; ++i) {
    for (int j = 0; j < b->width; ++j) {
      b->state[i][j] = kUnopen;
      b->number[i][j] = 0;
      b->mine[i][j] = false;
    }
  }
}

void generate_mine(struct Board *b, int mine_num) {
  uint8_t x;
  uint8_t y;
  while (mine_num--) {
    x = generate_random_num() % b->height;
    y = generate_random_num() % b->width;
    if (b->mine[x][y] == false) {
      b->mine[x][y] = true;
    } else {
      ++mine_num;
    }
  }
}

void first_click_with_mine(struct Board *b, int x, int y) {
  for (uint8_t i = 0; i < b->height; ++i) {
    for (uint8_t j = 0; j < b->width; ++j) {
      if (b->mine[i][j] == false && (i != x || j != y)) {
        b->mine[i][j] = true;
        b->mine[x][y] = false;
        return;
      }
    }
  }
}

void flag_cell(struct Board *b) {
  int x = BOARD_TOP_MARGIN + b->x * CELL_HEIGHT;
  int y = BOARD_LEFT_MARGIN + b->y * CELL_WIDTH;
  if (b->state[b->x][b->y] == kUnopen) {
    b->state[b->x][b->y] = kFlagged;
    ++b->flagged_num;
    draw_cell_background(x, y, kUnopenedBackgroundColor);
    draw_flag(x, y);
  } else if (b->state[b->x][b->y] == kFlagged) {
    b->state[b->x][b->y] = kUnopen;
    --b->flagged_num;
    draw_cell_background(x, y, kUnopenedBackgroundColor);
  }
}

void click_cell(struct Board *b) {
  if (b->is_first_click) {
    b->is_first_click = false;
    if (b->mine[b->x][b->y] == true) {
      first_click_with_mine(b, b->x, b->y);
    }
    uncover_cell(b, b->x, b->y);
  } else {
    if (b->state[b->x][b->y] == kUnopen || b->state[b->x][b->y] == kFlagged) {
      if (b->mine[b->x][b->y] == true) {
        int x = BOARD_TOP_MARGIN + b->x * CELL_HEIGHT;
        int y = BOARD_LEFT_MARGIN + b->y * CELL_WIDTH;
        b->state[b->x][b->y] = kMine;
        b->failed = true;
        b->god_mode = true;
        draw_cell_background(x, y, kBoomCellBackgroundColor);
        draw_mine(x, y);
      } else {
        uncover_cell(b, b->x, b->y);
      }
    }
  }
}

void uncover_cell(struct Board *b, int x, int y) {
  if (check_in_board(b, x, y) == false) {
    return;
  }
  if (b->state[x][y] != kUnopen && b->state[x][y] != kFlagged) {
    return;
  }
  if (b->mine[x][y] == true) {
    return;
  } else {
    int xx = BOARD_TOP_MARGIN + x * CELL_HEIGHT;
    int yy = BOARD_LEFT_MARGIN + y * CELL_WIDTH;
    draw_cell_background(xx, yy, kOpenedBackgroundColor);
    draw_cell_frame(xx, yy, 1, kFrameColor);
    ++b->unlocked_num;
    b->number[x][y] = count_surrounding_mines(b, x, y);
    if (b->number[x][y] == 0) {
      b->state[x][y] = kBlank;
      draw_blank_cell(xx, yy, kBlankCellColor);
      uncover_cell(b, x + 1, y);
      uncover_cell(b, x, y + 1);
      uncover_cell(b, x - 1, y);
      uncover_cell(b, x, y - 1);
    } else {
      b->state[x][y] = kNumbered;
      draw_digit(xx, yy, b->number[x][y], kCharacterColor);
    }
  }
}

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

uint8_t count_surrounding_mines(struct Board *b, int x, int y) {
  uint8_t val = 0;
  for (int i = 0; i < 8; ++i) {
    if (check_in_board(b, x + dx[i], y + dy[i]) == true) {
      val += b->mine[x + dx[i]][y + dy[i]] == true ? 1 : 0;
    }
  }
  return val;
}

void set_cursor(struct Board *b, uint16_t x, uint16_t y) {
  if (x < BOARD_TOP_MARGIN ||
      x >= (BOARD_TOP_MARGIN + b->height * CELL_HEIGHT)) {
    return;
  }
  if (y < BOARD_LEFT_MARGIN ||
      y >= (BOARD_LEFT_MARGIN + b->width * CELL_WIDTH)) {
    return;
  }
  b->x = (x - BOARD_TOP_MARGIN) / CELL_HEIGHT;
  b->y = (y - BOARD_LEFT_MARGIN) / CELL_WIDTH;
}

void god_mode(struct Board *b) {
  if (b->god_mode) {
    for (uint8_t i = 0; i < b->height; ++i) {
      for (uint8_t j = 0; j < b->width; ++j) {
        int x = BOARD_TOP_MARGIN + i * CELL_HEIGHT;
        int y = BOARD_LEFT_MARGIN + j * CELL_WIDTH;
        if (b->state[i][j] == kUnopen && b->mine[i][j]) {
          draw_cell_background(x, y, kUnopenedBackgroundColor);
          draw_cell_frame(x, y, 1, kFrameColor);
        }
      }
    }
  } else {
    for (uint8_t i = 0; i < b->height; ++i) {
      for (uint8_t j = 0; j < b->width; ++j) {
        int x = BOARD_TOP_MARGIN + i * CELL_HEIGHT;
        int y = BOARD_LEFT_MARGIN + j * CELL_WIDTH;
        if (b->state[i][j] == kUnopen && b->mine[i][j]) {
          draw_mine(x, y);
        }
      }
    }
  }
  b->god_mode ^= 1;
}