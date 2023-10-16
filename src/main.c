#include "board.h"
#include "draw.h"

#ifdef EASY
#define MINE_NUM 10
#elif NORMAL
#define MINE_NUM 40
#elif HARD
#define MINE_NUM 99
#endif

int main() {
  struct Board board;
  init_board(&board);
  generate_mine(&board, MINE_NUM);
  char command;
  while (true) {
    // command = getchar();
    if (board.failed == false) {
      switch (command) {
      case 'w':
        move_cursor_up(&board);
        break;
      case 'a':
        move_cursor_left(&board);
        break;
      case 's':
        move_cursor_down(&board);
        break;
      case 'd':
        move_cursor_right(&board);
        break;
      case 'f':
        flag_cell(&board);
        break;
      case 'o':
        click_cell(&board);
        break;
      case 'r':
        clear_board(&board);
        break;
      }
    } else {
      if (command == 'r') {
        clear_board(&board);
      }
    }
    // draw_board(&board);
  }
  return 0;
}