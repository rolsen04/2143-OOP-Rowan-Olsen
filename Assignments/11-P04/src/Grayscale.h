// Rowan Olsen
// CMPS 2143 Dr. Griffin
// Assignment 11 - Kernels & Convolution
// Date: May 4, 2026

#pragma once
#include "Filter.h"

// Converts every pixel to grayscale by setting all three channels to
//
// P04: paste your P03 implementation here, then optionally refactor it
//
//   double avg = (p[0] + p[1] + p[2]) / 3.0;
//   p = Color(static_cast<int>(avg), static_cast<int>(avg), static_cast<int>(avg));
//
// Or, using the luminance formula with Color arithmetic, if you want.
class Grayscale : public Filter {
public:
    void apply(Grid& pixels) override;
    std::string name() const override;  // returns "grayscale"
};
