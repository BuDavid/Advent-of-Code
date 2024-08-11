#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    void solve(const std::vector<std::string>& problem, int idx);
public:
    virtual int part_1(const std::vector<std::string>& problem) = 0;
    virtual int part_2(const std::vector<std::string>& problem) = 0;
};

#endif  // SOLUTION_H_
