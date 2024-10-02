#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <filesystem>
#include <map>
#include <utility>


namespace fs = std::filesystem;
using path_map_contain = std::map<std::string, std::vector<std::string>>;

class DataCSVGet
{
public:
    DataCSVGet(std::string path);
    ~DataCSVGet(){}
    bool dataDone();
    path_map_contain data_map_list{};
    std::string data_path{};
private:
    void traverseDirectory(const std::string &path, path_map_contain &pmc);

};