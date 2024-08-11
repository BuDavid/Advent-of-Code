#include "data_retriever.hpp"

std::vector<std::string> DataRetriever::get_data(const fs::path& input_path) const {
    std::vector<std::string> ans;

    fs::path problem_file = input_path / "problem.txt";
    if (fs::exists(problem_file)) {
        ans = get_data_from_file(problem_file);
    }

    /* if (ans.empty()) { */
    /*     ans = get_data_from_server(problem_file); */
    /* } */

    if (ans.empty()) {
        throw std::runtime_error("Error: Unable to retrieve data");
    }
    return ans;
}


std::vector<std::string> DataRetriever::get_data_from_file(const fs::path& file_path) const {
    std::vector<std::string> ans;
    std::ifstream file(file_path);
    
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << file_path << std::endl;
    } else {
        std::string line;
        while (std::getline(file, line)) {
            ans.push_back(line);
        }
        file.close();
    }

    return ans;
}

/* std::vector<std::string> DataRetriever::get_data_from_server(const fs::path& file_path) const { */
/* } */
