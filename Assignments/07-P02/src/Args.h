// Rowan Olsen
// CMPS 2143 Dr. Griffin
// Assignment 7 - Args Parser
// Date: March 16, 2026

#pragma once
#include <string>
#include <vector>

struct Args {
    std::string input;
    std::string output;

    bool grayscale = false;
    bool blur      = false;
    bool flipH     = false;
    bool flipV     = false;

    bool use_brighten = false;
    int  brighten     = 0;

    bool use_rotate = false;
    int  rotate     = 0;

    static Args parse(int argc, char* argv[]);
    void print() const;

private:
    Args() = default;
};