cmake_minimum_required(VERSION 3.20)
project(minesweeper)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER clang)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(minesweeper
  src/main.c
  src/board.c
  src/display.c
  src/draw.c
  src/font16x16.c
  src/graphics.c
  src/random.c
  src/sanae.c
  src/sdl_interface.c
  include/color.h
  include/board.h
  include/display.h
  include/draw.h
  include/font16x16.h
  include/graphics.h
  include/random.h
  include/sanae.h
  include/sdl_interface.h
)
target_link_libraries(minesweeper PUBLIC SDL2)

add_executable(minesweeper_rv
  src/main.c
  src/board.c
  src/display.c
  src/draw.c
  src/font16x16.c
  src/graphics.c
  src/random.c
  src/sanae.c
  src/device.c
  include/color.h
  include/board.h
  include/display.h
  include/draw.h
  include/font16x16.h
  include/graphics.h
  include/random.h
  include/sanae.h
  include/device.h
)
target_compile_options(minesweeper_rv PUBLIC
  --target=riscv32-unknown-unknown
  -march=rv32im
  -ffreestanding
  -fno-builtin
  -nostdlib
  -mno-relax
  -fno-PIE
  -G=0
  -Oz
  -flto
)
target_link_options(minesweeper_rv PUBLIC
  # -T ${CMAKE_SOURCE_DIR}/${LINKER_SCRIPT}
  --target=riscv32-unknown-unknown
  -march=rv32im
  -ffreestanding
  -fno-builtin -nostdlib
  -mno-relax
  -fno-PIE
  -G=0
  -Oz
  -flto
)

target_compile_definitions(minesweeper PUBLIC NORMAL)
target_compile_definitions(minesweeper_rv PUBLIC NORMAL RISCV)