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
  src/mouse.c
  include/color.h
  include/board.h
  include/display.h
  include/draw.h
  include/font16x16.h
  include/graphics.h
  include/random.h
  include/sanae.h
  include/sdl_interface.h
  include/mouse.h
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
  src/mouse.c
  include/color.h
  include/board.h
  include/display.h
  include/draw.h
  include/font16x16.h
  include/graphics.h
  include/random.h
  include/sanae.h
  include/device.h
  include/mouse.h
)
target_compile_options(minesweeper_rv PUBLIC
  --target=riscv32-unknown-elf
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
  -T ${PROJECT_SOURCE_DIR}/rv_linker.lds
  --target=riscv32-unknown-elf
  -march=rv32im
  -ffreestanding
  -fno-builtin
  -nostdlib
  -mno-relax
  -fno-PIE
  -G=0
  -Oz
  -g
  -flto
)

target_compile_definitions(minesweeper PUBLIC )
target_compile_definitions(minesweeper_rv PUBLIC RISCV SMALL_MEMORY)

add_custom_command(TARGET minesweeper_rv POST_BUILD
    COMMAND llvm-objcopy ./minesweeper_rv --dump-section .text=rom.bin --dump-section .data=ram.bin
    COMMAND od -w4 -An --endian little -v -t x4 ./rom.bin > rom.mem
    COMMAND od -w4 -An --endian little -v -t x4 ./ram.bin > ram.mem
    COMMAND llvm-objdump -S minesweeper_rv > tetris.asm
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating rom and ram files..."
)