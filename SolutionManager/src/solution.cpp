#include "solution.hpp"

void Solution::solve(const std::vector<std::string>& problem, int idx) {
    if (idx == 1) {
        std::cout << part_1(problem) << std::endl;
    } else {
        std::cout << part_2(problem) << std::endl;
    }
}
