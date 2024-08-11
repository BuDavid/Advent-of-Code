#ifndef SOLUTION_MANAGER_H__
#define SOLUTION_MANAGER_H__

#include <memory>
#include <filesystem>
#include "data_retriever.hpp"
#include "solution_factory.hpp"

enum class Timestamp {
    First_day = 1,
    Last_day = 25,
    First_year = 2015,
    Last_year = 3000
};

class SolutionManager {
public:
    SolutionManager(const std::string& day, const std::string& year, const std::string& part);
    void start();
private:
    bool validate_input(const std::string& day, const std::string& year, const std::string& part);
    static bool is_numeric(const std::string& str);
private:
    int m_day;
    int m_year;
    int m_part;
    std::unique_ptr<DataRetriever> m_data_retriever;
    fs::path m_input_path;
    std::unique_ptr<Solution> m_solution;
};

#endif  // SOLUTION_MANAGER_H__
