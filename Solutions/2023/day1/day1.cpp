#include "day1.hpp"

int Y2023Day1::part_1(const std::vector<std::string>& problem) {
    int ans = 0;
    for (auto str : problem) {
        ans += decode(str);
    }
    return ans;
}

int Y2023Day1::part_2(const std::vector<std::string>& problem) {
    return 0;
}

int Y2023Day1::get_int(char first, char last) {
	int num1 = (first - '0') * 10;
	if (last) {
		int num2 = last - '0';
		return num1 + num2;
	}
	int num2 = first - '0';

	return num1 + num2;
}


int Y2023Day1::decode(const std::string& str) {
	char first = 0;
	char last = 0;

    for (int i = 0, j = str.length() - 1; !(first && last);) {
        if (!first) { 
            if (str[i] <= '9' && str[i] >= '0') {
                first = str[i];
            }
            i++;
        }

        if (!last) {
            if (str[j] <= '9' && str[j] >= '0') {
                last = str[j];
            }
            j--;
        }
    }
	return get_int(first, last);;
}
