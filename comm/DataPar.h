#pragma once
#include "DataType.hpp"

class DataPar
{
public:
    DataPar();
    DataPar(std::vector<std::string> futures, int peroid);
    ~DataPar(){}
private:
    DataM dm;
};