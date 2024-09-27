#include<iostream>

#include "DataPar.h"

int main()
{
    std::vector<std::string> a = {"nihao", "woshi"};
    DataPar dp = DataPar(a,2);
    std::cout << "hello world" << std::endl;
    return 0;
}