// Rowan Olsen
// CMPS 2143 Dr. Griffin
// Assignment 10 - Filter Pipeline
// Date: April 24, 2026

#pragma once
#include <iostream>
#include <string>
#include <vector>

struct Pixel {
    int r = 0;
    int g = 0;
    int b = 0;
    Pixel() = default;
    Pixel(int r, int g, int b) : r(r), g(g), b(b) {}
};

inline std::ostream& operator<<(std::ostream& os, const Pixel& p) {
    return os << '(' << p.r << ',' << p.g << ',' << p.b << ')';
}
