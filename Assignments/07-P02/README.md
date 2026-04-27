## P02 - Command-Line Args Parser

### Rowan Olsen

### Description

Program 2 builds a command-line argument parser for the imgtool image processing utility. The parser handles positional arguments (input/output files), flags (--grayscale, --blur, --flipH, --flipV), and valued options (--brighten N, --rotate N). It validates all inputs and produces clear error messages.

### Files

|   #   | File            | Description                                        |
| :---: | --------------- | ------------------------------------------------ |
|   1   | [src/main.cpp](./src/main.cpp) | Main driver that calls Args::parse() and prints results |
|   2   | [src/Args.h](./src/Args.h) | Args class declaration |
|   3   | [src/Args.cpp](./src/Args.cpp) | Args implementation with parsing logic |

### Instructions

- Compile from the project root (07-P02/):
```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic src/main.cpp src/Args.cpp -o imgtool
```

- Run with valid input:
```bash
./imgtool in.png out.png --grayscale --brighten 20
```

- Run with invalid option to test error handling:
```bash
./imgtool in.png out.png --graycale
```

- Supported options:
  - `-g, --grayscale` — Convert to grayscale
  - `-l, --blur` — Apply blur filter
  - `-h, --flipH` — Flip horizontally
  - `-v, --flipV` — Flip vertically
  - `-b N, --brighten N` — Brightness adjustment (N in [-255, 255])
  - `-r N, --rotate N` — Rotation (N in {0, 90, 180, 270})
