// Rowan Olsen
// CMPS 2143 Dr. Griffin
// Assignment 11 - Kernels & Convolution
// Date: May 4, 2026

#pragma once
#include "Filter.h"

// Adds a fixed integer amount to every channel of every pixel.
// Positive amount = brighter; negative amount = darker.
//
//
// P04 note: 'Pixel' in the apply signature is an alias for 'Color'
// (defined in Filter.h). The implementation below uses direct channel
//
//   p = p + Color(amount_, amount_, amount_);
//
// Both are correct. The operator form is more expressive once Color
class Brighten : public Filter {
public:
    explicit Brighten(int amount);

    void apply(Grid& pixels) override;
    std::string name() const override;  // returns "brighten(N)"

private:
    int amount_;
};
