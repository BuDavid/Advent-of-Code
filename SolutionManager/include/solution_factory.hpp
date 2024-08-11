#ifndef SOLUTION_FACTORY_H_
#define SOLUTION_FACTORY_H_

#include <memory>
#include "solution.hpp"
#include "all_solutions.hpp"

class SolutionFactory {
public:
    static std::unique_ptr<Solution> create_solution(int day, int year);
private:
};

#endif  // SOLUTION_FACTORY_H_

