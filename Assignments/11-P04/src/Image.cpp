// Rowan Olsen
// CMPS 2143 Dr. Griffin
// Assignment 11 - Color, Kernels, and Convolution
// Date: May 4, 2026

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "Image.h"
#include "Kernel.h"
#include "stb_image.h"
#include "stb_image_write.h"

#include <algorithm>
#include <cctype>
#include <stdexcept>

static std::string toLower(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

Image::Image(int width, int height)
    : _width(width), _height(height),
      _pixels(height, std::vector<Color>(width)) {}

Image Image::load(const std::string& filename) {
    int width = 0, height = 0, channels = 0;
    unsigned char* data = stbi_load(filename.c_str(), &width, &height, &channels, 3);

    if (!data) {
        throw std::runtime_error("Image::load - cannot read file: " + filename);
    }

    Image img(width, height);

    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            int idx = (row * width + col) * 3;
            img._pixels[row][col].r = data[idx + 0];
            img._pixels[row][col].g = data[idx + 1];
            img._pixels[row][col].b = data[idx + 2];
        }
    }

    stbi_image_free(data);
    return img;
}

void Image::save(const std::string& filename, int jpegQuality) const {
    int actualHeight = static_cast<int>(_pixels.size());
    int actualWidth  = actualHeight > 0 ? static_cast<int>(_pixels[0].size()) : 0;

    std::vector<unsigned char> buf(actualWidth * actualHeight * 3);

    for (int row = 0; row < actualHeight; ++row) {
        for (int col = 0; col < actualWidth; ++col) {
            int idx = (row * actualWidth + col) * 3;
            buf[idx + 0] = static_cast<unsigned char>(std::clamp(_pixels[row][col].r, 0, 255));
            buf[idx + 1] = static_cast<unsigned char>(std::clamp(_pixels[row][col].g, 0, 255));
            buf[idx + 2] = static_cast<unsigned char>(std::clamp(_pixels[row][col].b, 0, 255));
        }
    }

    size_t dot = filename.rfind('.');
    std::string ext = (dot != std::string::npos) ? toLower(filename.substr(dot)) : "";

    int ok = 0;
    if (ext == ".jpg" || ext == ".jpeg") {
        ok = stbi_write_jpg(filename.c_str(), actualWidth, actualHeight, 3,
                            buf.data(), jpegQuality);
    } else {
        ok = stbi_write_png(filename.c_str(), actualWidth, actualHeight, 3,
                            buf.data(), actualWidth * 3);
    }

    if (!ok) {
        throw std::runtime_error("Image::save - cannot write file: " + filename);
    }
}

int Image::width()  const { return _width;  }
int Image::height() const { return _height; }

std::vector<Color>& Image::operator[](int row) {
    if (row < 0 || row >= _height)
        throw std::out_of_range("Image: row out of range");
    return _pixels[row];
}

const std::vector<Color>& Image::operator[](int row) const {
    if (row < 0 || row >= _height)
        throw std::out_of_range("Image: row out of range");
    return _pixels[row];
}

std::vector<std::vector<Color>>& Image::pixels() { return _pixels; }
const std::vector<std::vector<Color>>& Image::pixels() const { return _pixels; }

Image Image::apply(const Kernel& k) const {
    Image result(*this);
    int h = k.size() / 2;

    for (int row = h; row < _height - h; ++row) {
        for (int col = h; col < _width - h; ++col) {
            int sumR = 0, sumG = 0, sumB = 0;
            for (int ki = 0; ki < k.size(); ++ki) {
                for (int kj = 0; kj < k.size(); ++kj) {
                    int pr = row + ki - h;
                    int pc = col + kj - h;
                    double w = k.at(ki, kj);
                    sumR += static_cast<int>(_pixels[pr][pc].r * w);
                    sumG += static_cast<int>(_pixels[pr][pc].g * w);
                    sumB += static_cast<int>(_pixels[pr][pc].b * w);
                }
            }
            result._pixels[row][col].r = static_cast<unsigned char>(std::clamp(sumR, 0, 255));
            result._pixels[row][col].g = static_cast<unsigned char>(std::clamp(sumG, 0, 255));
            result._pixels[row][col].b = static_cast<unsigned char>(std::clamp(sumB, 0, 255));
        }
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Image& img) {
    return os << "Image(" << img._width << " x " << img._height
              << ", " << (img._width * img._height) << " pixels)";
}
