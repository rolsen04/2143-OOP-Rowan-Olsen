// Rowan Olsen
// CMPS 2143 Dr. Griffin
// Assignment 10 - Filter Pipeline
// Date: April 24, 2026

// Grayscale.cpp — converts every pixel to grayscale.
//
// Same nested-loop structure as Brighten.cpp: walk every row, walk every
// pixel in that row, replace its three channels with one luminance value.
// Pixel channels are int, so this arithmetic is safe; Image::save() clamps
// to [0, 255] when writing, so we don't clamp here.

#include "Grayscale.h"

std::string Grayscale::name() const {
    return "grayscale";
}

void Grayscale::apply(Grid& pixels) {
    for (auto& row : pixels) {
        for (Pixel& p : row) {
            // Luminance (Rec. 601) — perceptually weighted, not a flat
            // average. Green is weighted highest because the human eye
            // is most sensitive to green; blue is weighted lowest. The
            // weights sum to 1.0 so a fully white pixel (255,255,255)
            // stays at 255 and a fully black pixel (0,0,0) stays at 0.
            int gray = static_cast<int>(0.299 * p.r + 0.587 * p.g + 0.114 * p.b);
            p.r = gray;
            p.g = gray;
            p.b = gray;
        }
    }
}
