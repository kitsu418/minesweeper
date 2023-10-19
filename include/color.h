#pragma once

#include <stdint.h>
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
#define COLOR_MINE 0x000000FF
#define COLOR_MESSAGE 0x466E60FF

#define COLOR_SANAE_0 COLOR_BACKGROUND
#define COLOR_SANAE_1 0x000000FF
#define COLOR_SANAE_2 0x58B675FF
#define COLOR_SANAE_3 0xB95C39FF
#define COLOR_SANAE_4 0x1A9168FF
#define COLOR_SANAE_5 0xFFFFFFFF
#define COLOR_SANAE_6 0xC3D4FFFF
#define COLOR_SANAE_7 0x140700FF
#define COLOR_SANAE_8 0xB79800FF
#define COLOR_SANAE_9 0xFFE1BDFF
#define COLOR_SANAE_10 0x576C9EFF
#define COLOR_SANAE_11 0x6C5600FF
#define COLOR_SANAE_12 0xFEFEFEFF
#define COLOR_SANAE_13 0xDD9E81FF
#define COLOR_SANAE_14 0x8DA0CEFF
#define COLOR_SANAE_15 0x1B4618FF
#define COLOR_SANAE_16 0x9D4A25FF
#define COLOR_SANAE_17 0x8484C6FF
#define COLOR_SANAE_18 0x222254FF

enum ColorType : uint8_t {
  kBackgroundColor,
  kCharacterColor,
  kBoomCellBackgroundColor,
  kTitleColor,
  kMessageColor,
  kFlagColor,
  kFlagpoleColor,
  kFrameColor,
  kBlankCellColor,
  kCursorColor,
  kOpenedBackgroundColor,
  kUnopenedBackgroundColor,
  kMineColor,
  kSanaeColor0,
  kSanaeColor1,
  kSanaeColor2,
  kSanaeColor3,
  kSanaeColor4,
  kSanaeColor5,
  kSanaeColor6,
  kSanaeColor7,
  kSanaeColor8,
  kSanaeColor9,
  kSanaeColor10,
  kSanaeColor11,
  kSanaeColor12,
  kSanaeColor13,
  kSanaeColor14,
  kSanaeColor15,
  kSanaeColor16,
  kSanaeColor17,
  kSanaeColor18,
};