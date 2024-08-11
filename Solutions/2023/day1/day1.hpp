#ifndef Y2023DAY1_H_
#define Y2023DAY1_H_

#include <stdexcept>
#include <string>
#include <vector>
#include "solution.hpp"

class Y2023Day1 : public Solution {
private:
    int part_1(const std::vector<std::string>& problem) override;
    int part_2(const std::vector<std::string>& problem) override;
    int get_int(char first, char last);
    int decode(const std::string& str);
};

#endif  // Y2023DAY1_H_
