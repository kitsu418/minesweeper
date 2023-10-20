#include "draw.h"
#include "font16x16.h"
#include "mouse.h"

bool exit_button_activated(uint16_t x, uint16_t y) {
  return (x >= EXIT_BUTTON_TOP_MARGIN &&
          x < (EXIT_BUTTON_TOP_MARGIN + EXIT_BUTTON_HEIGHT) &&
          y >= EXIT_BUTTON_LEFT_MARGIN &&
          y < (EXIT_BUTTON_LEFT_MARGIN + EXIT_BUTTON_WIDTH));
}

bool restart_button_activated(uint16_t x, uint16_t y) {
  return (x >= RESTART_BUTTON_TOP_MARGIN &&
          x < (RESTART_BUTTON_TOP_MARGIN + RESTART_BUTTON_HEIGHT) &&
          y >= RESTART_BUTTON_LEFT_MARGIN &&
          y < (RESTART_BUTTON_LEFT_MARGIN + RESTART_BUTTON_WIDTH));
}
