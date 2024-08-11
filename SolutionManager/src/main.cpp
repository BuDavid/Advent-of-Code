#include <string>
#include <iostream>
#include "solution_manager.hpp"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " day year part" << std::endl;
        return 1;
    }

    SolutionManager mng(argv[1], argv[2], argv[3]);
    mng.start();
}

