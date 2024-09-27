#include "DataPar.h"
#include<iostream>

DataPar::DataPar()
{
}

DataPar::DataPar(std::vector<std::string> futures, int peroid)
{
    for(auto a : futures)
    {
        std::cout << a << std::endl;
    }
}
