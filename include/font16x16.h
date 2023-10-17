#pragma once
#include <stdint.h>

// 'A' - 'Z' INDEX: 0 - 25
#define DIGIT_INDEX 26
// '0' - '9' INDEX: 26 - 35
#define EXCLAM_INDEX 36
#define COMMA_INDEX 37
#define PERIOD_INDEX 38
#define EMPTY_INDEX 39
#define CHAR_WIDTH 16
#define CHAR_HEIGHT 14

extern uint32_t font[][14];
extern uint32_t mine_font[16];

uint8_t get_font_index(uint8_t c);