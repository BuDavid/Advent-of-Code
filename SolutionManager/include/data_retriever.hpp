#ifndef DATA_RETRIEVER_H_
#define DATA_RETRIEVER_H_

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

class DataRetriever {
public:
    std::vector<std::string> get_data(const fs::path& file_path) const; 
private:
    std::vector<std::string> get_data_from_file(const fs::path& file_path) const; 
    /* std::vector<std::string> get_data_from_server(const fs::path& file_path) const; */ 
};

#endif  // DATA_RETRIEVER_H_
