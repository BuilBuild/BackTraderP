#include "DataPar.h"
#include "rapidcsv.h"
#include<iostream>


DataPar::DataPar()
{
}

DataPar::DataPar(std::vector<std::string> futures, int peroid)
{
    for(auto a : futures)
    {
        // std::cout << a << std::endl;
        ;
    }
    readCSV("/home/leijiulong/git_project/BackTraderP/DataStore/csv/20240924_night/au2412_market_data.csv");
}

bool DataPar::readCSV(std::string path)
{
    std::string futures_name = "";
    // std::string::reverse_iterator rbegin = path.rbegin();
    for(auto rbegin=path.rbegin();rbegin< path.rend(); rbegin++ )
    {
        // std::cout << *rbegin << std::endl;
        if(*rbegin == '/')
        {
            rbegin--;
            while(rbegin >= path.rbegin())
            {
                futures_name += *rbegin;
                rbegin--;
                if(*rbegin=='_')
                    break;
            }
            break;
        }
    }
    std::cout << futures_name << std::endl;
    std::cout << &dm << std::endl;
    
    
    rapidcsv::Document doc(path, rapidcsv::LabelParams(0, 0));

    std::vector<int> Volume = doc.GetColumn<int>("Volume");
    std::cout << "Volume[0]  = " << Volume[0]<< std::endl;
    std::cout << "Volume[1]  = " << Volume[1] << std::endl;
    std::cout << "Volume[2]  = " << Volume[2] << std::endl;
    // for (auto item : Volume)
    //     std::cout << item << std::endl;


    return false;
}
