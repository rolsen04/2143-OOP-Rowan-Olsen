// Rowan Olsen
// CMPS 2143 Dr. Griffin
// Assignment 6 - Image Tool
// Date: March 9, 2026

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "stb_image.h"
#include "stb_image_write.h"
#include "termcolor.hpp"

using namespace termcolor;

bool open_file_default_app(const std::string& path) {
#if defined(_WIN32)
    std::string cmd = "start \"\" \"" + path + "\"";
#elif defined(__APPLE__)
    std::string cmd = "open \"" + path + "\"";
#else
    std::string cmd = "xdg-open \"" + path + "\"";
#endif
    return std::system(cmd.c_str()) == 0;
}

void apply_grayscale(unsigned char* data, int totalPixels, int channels) {
    for (int i = 0; i < totalPixels; ++i) {
        int idx = i * channels;
        int r = data[idx + 0];
        int g = data[idx + 1];
        int b = data[idx + 2];
        int gray = static_cast<int>(0.299 * r + 0.587 * g + 0.114 * b);
        unsigned char gr = static_cast<unsigned char>(std::clamp(gray, 0, 255));
        data[idx + 0] = gr;
        data[idx + 1] = gr;
        data[idx + 2] = gr;
    }
}

void apply_brighten(unsigned char* data, int totalPixels, int channels, int amount) {
    float factor = 1.0f + (amount / 100.0f);
    for (int i = 0; i < totalPixels; ++i) {
        int idx = i * channels;
        data[idx + 0] = static_cast<unsigned char>(std::clamp(static_cast<int>(data[idx + 0] * factor), 0, 255));
        data[idx + 1] = static_cast<unsigned char>(std::clamp(static_cast<int>(data[idx + 1] * factor), 0, 255));
        data[idx + 2] = static_cast<unsigned char>(std::clamp(static_cast<int>(data[idx + 2] * factor), 0, 255));
    }
}

void apply_flipH(unsigned char* data, int width, int height, int channels) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width / 2; ++x) {
            int left = y * width + x;
            int right = y * width + (width - 1 - x);
            for (int c = 0; c < channels; ++c) {
                unsigned char tmp = data[left * channels + c];
                data[left * channels + c] = data[right * channels + c];
                data[right * channels + c] = tmp;
            }
        }
    }
}

void apply_flipV(unsigned char* data, int width, int height, int channels) {
    for (int y = 0; y < height / 2; ++y) {
        for (int x = 0; x < width; ++x) {
            int top = y * width + x;
            int bottom = (height - 1 - y) * width + x;
            for (int c = 0; c < channels; ++c) {
                unsigned char tmp = data[top * channels + c];
                data[top * channels + c] = data[bottom * channels + c];
                data[bottom * channels + c] = tmp;
            }
        }
    }
}

void apply_rotate(unsigned char*& data, int& width, int& height, int channels, int degrees) {
    if (degrees == 90 || degrees == 270) {
        int newWidth = height;
        int newHeight = width;
        unsigned char* newData = new unsigned char[newWidth * newHeight * channels]();
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int srcIdx = (y * width + x) * channels;
                int dstIdx;
                if (degrees == 90) {
                    dstIdx = (x * newWidth + (newWidth - 1 - y)) * channels;
                } else {
                    dstIdx = ((newHeight - 1 - x) * newWidth + y) * channels;
                }
                for (int c = 0; c < channels; ++c) {
                    newData[dstIdx + c] = data[srcIdx + c];
                }
            }
        }
        delete[] data;
        data = newData;
        width = newWidth;
        height = newHeight;
    } else if (degrees == 180) {
        int totalPixels = width * height;
        for (int i = 0; i < totalPixels / 2; ++i) {
            int j = totalPixels - 1 - i;
            for (int c = 0; c < channels; ++c) {
                unsigned char tmp = data[i * channels + c];
                data[i * channels + c] = data[j * channels + c];
                data[j * channels + c] = tmp;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cout << red << "Usage: " << reset
                  << blue << "./imgtool <input_image> <output_image> <operations...>\n" << reset;
        std::cout << yellow << "Operations: grayscale, brighten, flipH, flipV, rotate(90/180/270)\n" << reset;
        return 1;
    }

    std::string inputPath = argv[1];
    std::string outputPath = argv[2];
    std::vector<std::string> operations;

    for (int i = 3; i < argc; ++i) {
        operations.push_back(argv[i]);
    }

    int width = 0, height = 0, channels_in_file = 0;
    unsigned char* data = stbi_load(inputPath.c_str(), &width, &height, &channels_in_file, 3);

    if (!data) {
        std::cerr << red << "Failed to load image: " << reset << inputPath << "\n";
        return 1;
    }

    const int channels = 3;
    const int totalPixels = width * height;

    std::cout << cyan << "Loaded image: " << reset << width << "x" << height
              << " channels: " << channels << "\n";

    for (const std::string& op : operations) {
        if (op == "grayscale") {
            apply_grayscale(data, totalPixels, channels);
            std::cout << green << "Applied grayscale\n" << reset;
        } else if (op.substr(0, 8) == "brighten") {
            int amount = 50;
            if (op.find(":") != std::string::npos) {
                amount = std::stoi(op.substr(op.find(":") + 1));
            }
            apply_brighten(data, totalPixels, channels, amount);
            std::cout << green << "Applied brighten (" << amount << ")\n" << reset;
        } else if (op == "flipH") {
            apply_flipH(data, width, height, channels);
            std::cout << green << "Applied flipH\n" << reset;
        } else if (op == "flipV") {
            apply_flipV(data, width, height, channels);
            std::cout << green << "Applied flipV\n" << reset;
        } else if (op.substr(0, 6) == "rotate") {
            int degrees = 90;
            if (op.find(":") != std::string::npos) {
                degrees = std::stoi(op.substr(op.find(":") + 1));
            }
            apply_rotate(data, width, height, channels, degrees);
            std::cout << green << "Applied rotate (" << degrees << ")\n" << reset;
        }
    }

    int outputWidth = width;
    int outputHeight = height;

    if (!stbi_write_png(outputPath.c_str(), outputWidth, outputHeight, channels, data, outputWidth * channels)) {
        std::cerr << red << "Failed to write output image: " << reset << outputPath << "\n";
        stbi_image_free(data);
        return 1;
    }

    stbi_image_free(data);

    std::cout << green << "Saved output to: " << reset << yellow << outputPath << reset << "\n";

    std::cout << cyan << "Opening output in default viewer...\n" << reset;
    if (!open_file_default_app(outputPath)) {
        std::cout << yellow << "Warning: could not launch viewer automatically.\n" << reset;
    }

    return 0;
}
