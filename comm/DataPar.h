#pragma once
#include "DataType.hpp"
#define __USE_TIME_BITS64

class DataPar
{
public:
    DataPar();
    DataPar(std::vector<std::string> futures, int peroid);
    ~DataPar(){}
private:
    DataM dm;
    bool readCSV(std::string path, int period);
    bool dataPush();
};