// FlipV.cpp — mirrors the image top-to-bottom.
//
// std::swap on std::vector<Pixel> swaps the two vectors' internal
// pointers in O(1), so swapping whole rows is far cheaper than swapping
// pixel-by-pixel. Loop only to height/2 — past the midpoint we'd re-swap
// rows back into their original positions.
//
// Image dimensions are unchanged.

#include "FlipV.h"
#include <algorithm>   // std::swap
#include <cstddef>     // std::size_t

std::string FlipV::name() const {
    return "flipV";
}

void FlipV::apply(Grid& pixels) {
    const std::size_t height = pixels.size();
    const std::size_t half   = height / 2;   // middle row of an odd-height
                                             // image stays in place

    for (std::size_t row = 0; row < half; ++row) {
        std::swap(pixels[row], pixels[height - 1 - row]);
    }
}
