// Rowan Olsen
// CMPS 2143 Dr. Griffin
// Assignment 11 - Kernels & Convolution
// Date: May 4, 2026

#pragma once
#include "Filter.h"

// Rotates the image clockwise by 0°, 90°, 180°, or 270°.
// 90° and 270° rotations swap width and height — the Grid is rebuilt
class Rotate : public Filter {
public:
    explicit Rotate(int degrees);  // must be 0, 90, 180, or 270

    void apply(Grid& pixels) override;
    std::string name() const override;  // returns "rotate(N)"

private:
    int degrees_;
};
