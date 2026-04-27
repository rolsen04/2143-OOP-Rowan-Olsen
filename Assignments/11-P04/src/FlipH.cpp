// FlipH.cpp — mirrors the image left-to-right.
//
// For each row, swap col 0 with col width-1, col 1 with col width-2,
// and so on toward the middle. Iterating col from 0 to width/2 (exclusive)
// is critical: continuing past the midpoint would re-swap pixels that are
// already in their final positions, undoing the flip.
//
// Image dimensions are unchanged.

#include "FlipH.h"
#include <algorithm>   // std::swap
#include <cstddef>     // std::size_t

std::string FlipH::name() const {
    return "flipH";
}

void FlipH::apply(Grid& pixels) {
    if (pixels.empty()) return;

    const std::size_t width = pixels[0].size();
    const std::size_t half  = width / 2;     // integer division: middle col
                                             // of an odd-width row is fixed

    for (auto& row : pixels) {
        for (std::size_t col = 0; col < half; ++col) {
            std::swap(row[col], row[width - 1 - col]);
        }
    }
}
