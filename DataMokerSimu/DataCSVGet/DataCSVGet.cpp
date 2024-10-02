#include "DataCSVGet.h"
#include <algorithm>


DataCSVGet::DataCSVGet(std::string path):data_path(path)
{
}

bool DataCSVGet::dataDone()
{
    traverseDirectory(data_path, data_map_list);
    for(auto iter=data_map_list.begin(); iter != data_map_list.end(); ++iter)
    {
        std::sort(iter->second.begin(), iter->second.end());
    }
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
