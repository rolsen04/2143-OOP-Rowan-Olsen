## P01 - Image Tool

### Rowan Olsen

### Description

Program 1 builds an image processing tool that converts images to grayscale using the luminance formula. The tool loads an image, applies grayscale conversion, and saves the result as a PNG. Features colored terminal output using the termcolor library and auto-opens the output image in the system viewer.

### Files

|   #   | File              | Description                                      |
| :---: | ----------------- | ------------------------------------------------ |
|   1   | [src/main.cpp](./src/main.cpp) | Main driver with grayscale conversion and colored output |
|   2   | [include/stb_image.h](./include/stb_image.h) | Image loading library (third-party) |
|   3   | [include/stb_image_write.h](./include/stb_image_write.h) | Image writing library (third-party) |
|   4   | [include/termcolor.hpp](./include/termcolor.hpp) | Colored terminal output library |
|   5   | [images/Hulda.png](./images/Hulda.png) | Test input image |
|   6   | [images/Hulda.jpg](./images/Hulda.jpg) | Alternate test input |

### Instructions

- Compile from the project root (06-P01/):
```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic -Iinclude src/main.cpp -o imgtool
```

- Run with input and output files:
```bash
./imgtool images/Hulda.png output.png
```

- Required arguments: `<input_image> <output_image>`
