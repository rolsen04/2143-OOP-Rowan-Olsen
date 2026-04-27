// Rowan Olsen
// CMPS 2143 Dr. Griffin
// Assignment 7 - Args Parser
// Date: March 16, 2026

#include "Args.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

inline std::pair<std::string, std::string> splitEq(const std::string& token) {
    size_t pos = token.find('=');
    if (pos == std::string::npos)
        return {token, ""};
    return {token.substr(0, pos), token.substr(pos + 1)};
}

inline bool startsWith(const std::string& s, const std::string& prefix) {
    return s.size() >= prefix.size() && s.substr(0, prefix.size()) == prefix;
}

inline bool isImageFile(const std::string& filename) {
    static const std::vector<std::string> exts = {".png", ".jpg", ".jpeg", ".bmp", ".ppm"};
    for (const auto& e : exts) {
        if (filename.size() >= e.size() &&
            filename.substr(filename.size() - e.size()) == e)
            return true;
    }
    return false;
}

inline bool isInt(const std::string& s) {
    if (s.empty()) return false;
    size_t i = 0;
    if (s[0] == '-') { if (s.size() == 1) return false; i = 1; }
    for (; i < s.size(); ++i) if (s[i] < '0' || s[i] > '9') return false;
    return true;
}

inline void error(const std::string& msg) {
    std::cerr << msg << "\n";
    std::cerr << "Usage: ./imgtool <input_image> <output_image> [options]\n";
    std::exit(1);
}

Args Args::parse(int argc, char* argv[]) {
    Args args;
    std::vector<std::string> tokens;
    for (int i = 1; i < argc; ++i)
        tokens.push_back(argv[i]);

    if (tokens.empty())
        error("Error: at least one argument required");

    if (isImageFile(tokens.front()))
        args.input = tokens.front();
    else
        error("Error: input file must be a recognized image extension (.png, .jpg, .jpeg, .bmp, .ppm)");
    tokens.erase(tokens.begin());

    if (tokens.empty())
        error("Error: output file is required");
    if (!isImageFile(tokens.front()))
        error("Error: output file must be a recognized image extension (.png, .jpg, .jpeg, .bmp, .ppm)");
    args.output = tokens.front();
    tokens.erase(tokens.begin());

    while (!tokens.empty()) {
        auto [flag, inline_val] = splitEq(tokens.front());
        tokens.erase(tokens.begin());

        if (flag == "--grayscale" || flag == "-g") {
            args.grayscale = true;
        } else if (flag == "--blur" || flag == "-l") {
            args.blur = true;
        } else if (flag == "--flipH" || flag == "-h") {
            args.flipH = true;
        } else if (flag == "--flipV" || flag == "-v") {
            args.flipV = true;
        } else if (flag == "--brighten" || flag == "-b") {
            std::string val = inline_val.empty() ? "" : inline_val;
            if (val.empty()) {
                if (tokens.empty())
                    error("Error: '--brighten' requires an integer value");
                val = tokens.front();
                tokens.erase(tokens.begin());
            }
            if (!isInt(val))
                error("Error: invalid integer for '--brighten': '" + val + "'");
            int n = std::stoi(val);
            if (n < -255 || n > 255)
                error("Error: '--brighten' must be in [-255, 255]");
            args.use_brighten = true;
            args.brighten = n;
        } else if (flag == "--rotate" || flag == "-r") {
            std::string val = inline_val.empty() ? "" : inline_val;
            if (val.empty()) {
                if (tokens.empty())
                    error("Error: '--rotate' requires an integer value");
                val = tokens.front();
                tokens.erase(tokens.begin());
            }
            if (!isInt(val))
                error("Error: invalid integer for '--rotate': '" + val + "'");
            int n = std::stoi(val);
            if (n != 0 && n != 90 && n != 180 && n != 270)
                error("Error: '--rotate' must be one of {0, 90, 180, 270}");
            args.use_rotate = true;
            args.rotate = n;
        } else {
            error("Error: unknown option '" + flag + "'");
        }
    }

    return args;
}

void Args::print() const {
    std::cout << "INPUT  : " << input << "\n";
    std::cout << "OUTPUT : " << output << "\n";
    std::cout << "FLAGS  :";
    if (grayscale) std::cout << " grayscale";
    if (blur)      std::cout << " blur";
    if (flipH)     std::cout << " flipH";
    if (flipV)     std::cout << " flipV";
    std::cout << "\n";
    std::cout << "PARAMS :";
    if (use_brighten) std::cout << " brighten=" << brighten;
    if (use_rotate)   std::cout << " rotate=" << rotate;
    std::cout << "\n";
}