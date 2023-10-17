#pragma once
#include <stdint.h>

void set_vram(int x, int y, uint8_t color);
void commit_vram();