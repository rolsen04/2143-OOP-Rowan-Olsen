// Rowan Olsen
// CMPS 2143 Dr. Griffin
// Assignment 10 - Filter Pipeline
// Date: April 24, 2026

#include "Args.h"
#include "Image.h"
#include "Pipeline.h"
#include "Grayscale.h"
#include "Brighten.h"
#include "FlipH.h"
#include "FlipV.h"
#include "Blur.h"
#include "Rotate.h"

#include <iostream>

int main(int argc, char* argv[]) {
    Args args = Args::parse(argc, argv);
    args.print();
    std::cout << "\n";

    Image img = Image::load(args.input);
    std::cout << "Loaded: " << img << "\n";

    Pipeline pipeline;

    for (const std::string& op : args.order) {
        if (op == "grayscale") {
            pipeline.add(new Grayscale());
        } else if (op == "brighten") {
            pipeline.add(new Brighten(args.brighten));
        } else if (op == "blur") {
            pipeline.add(new Blur());
        } else if (op == "flipH") {
            pipeline.add(new FlipH());
        } else if (op == "flipV") {
            pipeline.add(new FlipV());
        } else if (op == "rotate") {
            pipeline.add(new Rotate(args.rotate));
        }
    }

    pipeline.printSteps();
    pipeline.run(img.pixels());

    img.save(args.output);
    std::cout << "Saved: " << args.output << "\n";

    return 0;
}