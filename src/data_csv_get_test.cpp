#include<iostream>
#include<string>
#include "DataCSVGet.h"

using std::string;
int main()
{
    string path = "/home/leijiulong/桌面/datastore";
    DataCSVGet dc(path);
    dc.dataDone();
    std::cout << "hello" << std::endl;
}