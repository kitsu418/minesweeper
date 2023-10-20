#pragma once

#include <stdint.h>
#define COLOR_BACKGROUND 0xF0A0C0FF
#define COLOR_CHARACTER 0xF0F0D0FF
#define COLOR_BOOM_BACKGROUND 0xE06040FF
#define COLOR_TITLE 0x603080FF
#define COLOR_FLAG 0xE06040FF
#define COLOR_FLAGPOLE 0x000000FF
#define COLOR_UNOPENED 0xD0A0C0FF
#define COLOR_OPENED 0xA0A0C0FF
#define COLOR_CURSOR 0xF00000FF
#define COLOR_FRAME 0x000000FF
#define COLOR_MINE 0x000000FF
#define COLOR_MESSAGE 0x406060FF

#define COLOR_SANAE_0 COLOR_BACKGROUND
#define COLOR_SANAE_1 0x000000FF
#define COLOR_SANAE_2 0x50B070FF
#define COLOR_SANAE_3 0xB05030FF
#define COLOR_SANAE_4 0x109060FF
#define COLOR_SANAE_5 0xF0F0F0FF
#define COLOR_SANAE_6 0xC0D0F0FF
#define COLOR_SANAE_7 0x100000FF
#define COLOR_SANAE_8 0xB09000FF
#define COLOR_SANAE_9 0xF0E0B0FF
#define COLOR_SANAE_10 0x506090FF
#define COLOR_SANAE_11 0x605000FF
#define COLOR_SANAE_12 0xF0F0F0FF
#define COLOR_SANAE_13 0xD09080FF
#define COLOR_SANAE_14 0x80A0C0FF
#define COLOR_SANAE_15 0x104010FF
#define COLOR_SANAE_16 0x904020FF
#define COLOR_SANAE_17 0x8080C0FF
#define COLOR_SANAE_18 0x202050FF

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