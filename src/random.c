#include "random.h"

uint32_t random_state = 114514;

// a simple random number generator, based on xorshift32 algorithm
uint32_t generate_random_num() {
  uint32_t x = random_state;
  x ^= x << 13;
  x ^= x >> 17;
  x ^= x << 5;
  random_state = x;
  return x;
}