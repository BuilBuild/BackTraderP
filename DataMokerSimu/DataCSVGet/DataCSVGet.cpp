#include "DataCSVGet.h"



DataCSVGet::DataCSVGet(std::string path):data_path(path)
{
}

bool DataCSVGet::dataDone()
{
    traverseDirectory(data_path, data_map_list);
}

void DataCSVGet::traverseDirectory(const std::string &path, path_map_contain &pmc)
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
