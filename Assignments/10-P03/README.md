## P03 - Image Filter Pipeline

### Rowan Olsen

### Description

Program 3 implements an image processing pipeline using the Strategy pattern. Each filter (Grayscale, Brighten, Blur, FlipH, FlipV, Rotate) is a separate class inheriting from a common Filter interface. A Pipeline object manages filters and applies them in command-line order. The Args parser from P02 drives the pipeline configuration.

### Files

|   #   | File              | Description                                      |
| :---: | ----------------- | ------------------------------------------------ |
|   1   | [src/main.cpp](./src/main.cpp) | Main driver wiring Args to Pipeline to Image |
|   2   | [src/Image.h](./src/Image.h) | Image class with pixel grid and file I/O |
|   3   | [src/Image.cpp](./src/Image.cpp) | Image implementation |
|   4   | [src/Args.h](./src/Args.h) | Args class declaration (from P02) |
|   5   | [src/Args.cpp](./src/Args.cpp) | Args implementation |
|   6   | [src/Filter.h](./src/Filter.h) | Abstract base Filter class |
|   7   | [src/Pipeline.h](./src/Pipeline.h) | Pipeline class declaration |
|   8   | [src/Pipeline.cpp](./src/Pipeline.cpp) | Pipeline implementation |
|   9   | [src/Grayscale.cpp](./src/Grayscale.cpp) | Grayscale filter (luminance formula) |
|   10  | [src/Brighten.cpp](./src/Brighten.cpp) | Brightness adjustment filter |
|   11  | [src/Blur.cpp](./src/Blur.cpp) | 3x3 box blur filter |
|   12  | [src/FlipH.cpp](./src/FlipH.cpp) | Horizontal flip (mirror left-right) |
|   13  | [src/FlipV.cpp](./src/FlipV.cpp) | Vertical flip (mirror top-bottom) |
|   14  | [src/Rotate.cpp](./src/Rotate.cpp) | Rotation by 0, 90, 180, or 270 degrees |

### Instructions

- Compile from the project root (10-P03/):
```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic -isystem include -Isrc \
    src/main.cpp src/Image.cpp src/Pipeline.cpp \
    src/Grayscale.cpp src/Brighten.cpp src/FlipH.cpp \
    src/FlipV.cpp src/Blur.cpp src/Rotate.cpp \
    src/Args.cpp -o imgtool
```

- Example commands:
```bash
./imgtool images/Hulda.jpg out.png --grayscale
./imgtool images/Hulda.jpg out.png --brighten 50 --grayscale
./imgtool images/Hulda.jpg out.png -g -b 40 -l
```

- Filter order matters — `--grayscale --brighten 80` produces a different result than `--brighten 80 --grayscale`.
