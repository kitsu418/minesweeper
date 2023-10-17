#pragma once

#define COLOR_BACKGROUND 0xFFACC7FF
#define COLOR_CHARACTER 0xF6FED0FF
#define COLOR_BOOM_BACKGROUND 0xEF6F4FFF
#define COLOR_TITLE 0x633F82FF
#define COLOR_FLAG 0xEF6F4FFF
#define COLOR_FLAGPOLE 0x000000FF
#define COLOR_UNOPENED 0xD3ACC7FF
#define COLOR_OPENED 0xACACC7FF
#define COLOR_CURSOR 0xFF0000FF
#define COLOR_FRAME 0x000000FF

enum ColorType {
  kBackgroundColor,
  kCharacterColor,
  kBoomCellBackgroundColor,
  kTitleColor,
  kFlagColor,
  kFlagpoleColor,
  kFrameColor,
  kBlankCellColor,
  kCursorColor,
  kOpenedBackgroundColor,
  kUnopenedBackgroundColor,
};