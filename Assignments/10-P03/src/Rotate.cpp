// Rowan Olsen
// CMPS 2143 Dr. Griffin
// Assignment 10 - Filter Pipeline
// Date: April 24, 2026

// Rotate.cpp — clockwise rotation by 0, 90, 180, or 270 degrees.
//
// 90° and 270° swap the image's width and height, so we cannot rotate in
// place — we must build a fresh Grid with swapped dimensions and assign
// it back to `pixels`. 180° keeps the same dimensions but we still build a
// copy so we don't read from cells we've already overwritten.
//
// Pixel mapping table (from the assignment spec, all clockwise):
//
//   90°  : new[col][height-1-row]        = old[row][col]   (W × H -> H × W)
//   180° : new[height-1-row][width-1-col] = old[row][col]   (same dims)
//   270° : new[width-1-col][row]         = old[row][col]   (W × H -> H × W)
//
// Args validates the angle before constructing Rotate, so an unknown
// `degrees_` here is a programmer error — we simply leave `pixels`
// unchanged.

#include "Rotate.h"
#include <cstddef>   // std::size_t
#include <string>
#include <utility>   // std::move

Rotate::Rotate(int degrees) : degrees_(degrees) {}

std::string Rotate::name() const {
    return "rotate(" + std::to_string(degrees_) + ")";
}

void Rotate::apply(Grid& pixels) {
    if (degrees_ == 0 || pixels.empty() || pixels[0].empty()) return;

    const std::size_t height = pixels.size();
    const std::size_t width  = pixels[0].size();

    if (degrees_ == 180) {
        // Same dimensions: H rows of W columns.
        Grid result(height, std::vector<Pixel>(width));
        for (std::size_t row = 0; row < height; ++row) {
            for (std::size_t col = 0; col < width; ++col) {
                result[height - 1 - row][width - 1 - col] = pixels[row][col];
            }
        }
        pixels = std::move(result);
    } else if (degrees_ == 90) {
        // New dimensions: W rows of H columns.
        Grid result(width, std::vector<Pixel>(height));
        for (std::size_t row = 0; row < height; ++row) {
            for (std::size_t col = 0; col < width; ++col) {
                result[col][height - 1 - row] = pixels[row][col];
            }
        }
        pixels = std::move(result);
    } else if (degrees_ == 270) {
        // New dimensions: W rows of H columns.
        Grid result(width, std::vector<Pixel>(height));
        for (std::size_t row = 0; row < height; ++row) {
            for (std::size_t col = 0; col < width; ++col) {
                result[width - 1 - col][row] = pixels[row][col];
            }
        }
        pixels = std::move(result);
    }
    // Any other value: leave pixels unchanged (Args should have rejected it).
}
