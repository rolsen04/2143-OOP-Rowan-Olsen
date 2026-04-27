## P04 - Color, Kernels, and Convolution

### Rowan Olsen

### Description

Program 4 extends the P03 image pipeline with two major additions. First, a Color class replaces the raw Pixel struct with operator overloading (+, *, ==) and named constructors (fromRGB, fromHex, fromHSL). Second, a Kernel class generalizes convolution filters — the same algorithm produces blur, sharpen, edge detection, emboss, and gaussian blur effects by changing only the 3x3 kernel values. KernelFilter bridges kernels into the existing Pipeline.

### Files

|   #   | File              | Description                                      |
| :---: | ----------------- | ------------------------------------------------ |
|   1   | [src/main.cpp](./src/main.cpp) | Main driver wiring Args to Pipeline |
|   2   | [src/Image.h](./src/Image.h) | Image class with Color-based pixel grid |
|   3   | [src/Image.cpp](./src/Image.cpp) | Image implementation with apply() method |
|   4   | [src/Color.h](./src/Color.h) | Color class with operator overloading |
|   5   | [src/Color.cpp](./src/Color.cpp) | Color operators and named constructors |
|   6   | [src/Kernel.h](./src/Kernel.h) | Kernel class with 3x3 convolution grid |
|   7   | [src/Kernel.cpp](./src/Kernel.cpp) | Kernel factories (blur, sharpen, edge, etc.) |
|   8   | [src/Filter.h](./src/Filter.h) | Abstract base Filter class |
|   9   | [src/Pipeline.h](./src/Pipeline.h) | Pipeline class declaration |
|   10  | [src/Pipeline.cpp](./src/Pipeline.cpp) | Pipeline implementation |
|   11  | [src/KernelFilter.h](./src/KernelFilter.h) | Bridge from Kernel to Filter interface |
|   12  | [src/KernelFilter.cpp](./src/KernelFilter.cpp) | Convolution loop implementation |
|   13  | [src/Brighten.cpp](./src/Brighten.cpp) | Brightness adjustment |
|   14  | [src/Grayscale.cpp](./src/Grayscale.cpp) | Grayscale filter |
|   15  | [src/FlipH.cpp](./src/FlipH.cpp) | Horizontal flip |
|   16  | [src/FlipV.cpp](./src/FlipV.cpp) | Vertical flip |
|   17  | [src/Rotate.cpp](./src/Rotate.cpp) | Rotation by 0, 90, 180, 270 degrees |

### Instructions

- Compile from the project root (11-P04/):
```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic -isystem include -Isrc \
    src/main.cpp src/Image.cpp src/Color.cpp src/Kernel.cpp \
    src/Pipeline.cpp src/KernelFilter.cpp \
    src/Brighten.cpp src/Grayscale.cpp \
    src/FlipH.cpp src/FlipV.cpp src/Rotate.cpp \
    src/Args.cpp -o imgtool
```

- Example commands:
```bash
./imgtool images/Hulda.jpg out.png --grayscale --brighten 30
./imgtool images/Hulda.jpg out.png --sharpen
./imgtool images/Hulda.jpg out.png --gaussian --sharpen
./imgtool images/Hulda.jpg out.png -g -s -b 10
```
