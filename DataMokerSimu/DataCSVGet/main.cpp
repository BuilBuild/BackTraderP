
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

void traverseDirectory(const std::string &path, path_map_contain &pmc);

void traverseDirectory(const std::string &path, path_map_contain &pmc)
{
    for (const auto &entry : fs::directory_iterator(path))
    {
        if (entry.is_directory())
        {
            traverseDirectory(entry.path().string(), pmc);
        }
        else if (entry.is_regular_file() && entry.path().extension().string() == ".csv")
        {
            std::string filename = entry.path().filename().string();

            std::string c = std::string(filename.begin(), filename.end() - 16);
            // std::cout << c << std::endl;
            auto i = pmc.find(c);
            if (i == pmc.end())
            {
                auto p = std::make_pair(c, std::vector<std::string>());
                p.second.push_back(entry.path().string());
                pmc.insert(p);
            }
            else
            {
                i->second.push_back(entry.path().string());
            }
        }
    }
}

int main()
{

    std::string targetPath = "/home/leijiulong/桌面/datastore";

    path_map_contain a{};
    auto c = std::filesystem::path(targetPath);
    traverseDirectory(c, a);
    std::cout << &a << std::endl;
    std::cout << "hello" << std::endl;
    for(auto i: a)
    {
        std::cout << "key: " << i.first << std::endl;
        for(auto v:i.second)
        {
            std::cout << "\t" << v << std::endl;
        }
    }

    return 0;
}