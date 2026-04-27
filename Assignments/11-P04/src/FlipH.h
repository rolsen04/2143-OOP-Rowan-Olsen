// Rowan Olsen
// CMPS 2143 Dr. Griffin
// Assignment 11 - Kernels & Convolution
// Date: May 4, 2026

#pragma once
#include "Filter.h"
#include <algorithm>  // std::swap

// Mirrors the image left-to-right (horizontal flip).
// Image dimensions are unchanged.
class FlipH : public Filter {
public:
    void apply(Grid& pixels) override;
    std::string name() const override;  // returns "flipH"
};
