#include "solution_manager.hpp"

SolutionManager::SolutionManager(const std::string& day, const std::string& year, const std::string& part) : m_data_retriever(std::make_unique<DataRetriever>()) {
    m_input_path = fs::current_path() / "Solutions" / year / ("day" + day);
    if (!validate_input(day, year, part)) {
        throw std::invalid_argument("Error: Invalid input");
    }
}

void SolutionManager::start() {
    auto data = m_data_retriever -> get_data(m_input_path);
    auto solution = SolutionFactory::create_solution(m_day, m_year);
    solution -> solve(data, m_part); 
}

bool SolutionManager::validate_input(const std::string& day, const std::string& year, const std::string& part) {
    if (!(is_numeric(day) && is_numeric(year) && is_numeric(part))) {
        return false;
    }

    m_day = std::stoi(day);
    if (m_day < static_cast<int>(Timestamp::First_day) || m_day > static_cast<int>(Timestamp::Last_day)) {
        return false;
    }

    m_year = std::stoi(year);
    if (m_year < static_cast<int>(Timestamp::First_year) || m_year > static_cast<int>(Timestamp::Last_year)) {
        return false;
    }

    m_part = std::stoi(part);
    if (!(m_part == 1 || m_part == 2)) {
        return false;
    }

    if (!fs::exists(m_input_path)) {
        return false;
    }

    return true; 
}

bool SolutionManager::is_numeric(const std::string& str) {
    for (auto ch : str) {
        if (ch >= '0' && ch <= '9') {
            continue;
        }
        return false;
    }
    return true;
}
