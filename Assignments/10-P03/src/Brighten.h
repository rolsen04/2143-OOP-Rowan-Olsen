// Rowan Olsen
// CMPS 2143 Dr. Griffin
// Assignment 10 - Filter Pipeline
// Date: April 24, 2026

#pragma once
#include "Filter.h"

// Adds a fixed integer amount to every channel of every pixel.
// Positive amount = brighter; negative amount = darker.
//
class Brighten : public Filter {
public:
    explicit Brighten(int amount);

    void apply(Grid& pixels) override;
    std::string name() const override;  // returns "brighten(N)"

private:
    int amount_;
};
