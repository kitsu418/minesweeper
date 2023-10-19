# MINESWEEPER!

<p align="center">
  <img height=250 src="./resources/preview_win.png">
  <img height=250 src="./resources/preview.png">
  <img height=250 src="./resources/preview_gg.png">
</p>

MINESWEEPER! is my project of hardware system at HUST, fall 2023. In this project, I developed a simplified minesweeper game, which supports:
- A 16x16 game board with 40 mines.
- Random generation of mine layouts.
- Ensuring that the first clicked cell will not be a mine.
- Marking flags on the cells freely.
- Running on a self-made RISC-V CPU.
- Running on x86 machines via SDL2.

## Requirements
```bash
paru -S clang lld cmake
```

## Build & Run
```bash
cmake -B build
cd build && make
./minesweeper
```

## Usage
- Use WASD to move the cursor.
- Press O to open the tile.
- Press F to mark the flag.
- Press R to restart the game.
- Press Q to quit the game.

## TODO
- [x] Support receiving inputs from PS2 keyboard (on self-made RISC-V CPU).
- [x] Optimize the color scheme to make the UI more beautiful.
- [ ] Support mouse for x86 machines.
- [x] Add a window containing some information about the game.
- [x] Add a message bar to guide players.
- [x] ~~Add a cheating button.~~