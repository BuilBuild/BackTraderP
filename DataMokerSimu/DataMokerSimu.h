#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DataCSVGet.h"

typedef struct QuoteMsg
{
    std::vector<std::string> ql;
    std::string sTime;
    std::string eTime;
    float peroid;
}QuoteMsg;



class FileReadRecoder
{
public:
    const std::vector<std::string> *data_file_list=nullptr;
public:
    FileReadRecoder(const std::vector<std::string> *p):data_file_list(p)
    {
        std::cout << "File Reader ini" << std::endl;
    }
    ~FileReadRecoder(){
        // std::cout << "delete" << std::endl;
    }
};

class DataMokerSimu
{
private:
    DataCSVGet *dcg = nullptr;
    std::vector<std::string> *quote_list = nullptr;
    float quote_period{};
    std::vector<FileReadRecoder *> frr{};
    
public:
    DataMokerSimu(std::string DataPath);
    ~DataMokerSimu()
    {
        for(auto &i:frr)
        {
            delete i;
        }
        delete dcg;
        dcg=nullptr;
    }
    void setQuoteMsg(QuoteMsg & qm);
    void done();
};