#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DataCSVGet.h"
#include <memory>
#include "rapidcsv.h"

typedef struct QuoteMsg
{
    std::vector<std::string> ql;
    std::string sTime;
    std::string eTime;
    float peroid;
} QuoteMsg;

class FileReadRecoder
{
public:
    const std::vector<std::string> *data_file_list = nullptr;
    std::string quote_name{};
    std::string file_dir{};
    float period{};
    std::string sTime{};
    std::string eTime{};
    double s_time{};
    double e_time{};
    double time_now{};
    double time_pre{};
    double time_next{};
    std::string date_now{};
    bool prepared = false;
    // 用于指向data_file_list中的元素
    size_t file_path_index = 0;

    FileReadRecoder(const std::vector<std::string> *p) : data_file_list(p)
    {
        // std::cout << data_file_list->size() << std::endl;
        // std::cout << "first: "<< data_file_list->at(0) << std::endl;
    }
    ~FileReadRecoder()
    {
        // std::cout << "delete" << std::endl;
    }
    void next();
    void prepare();

private:
    //"2024-09-27 09:10:30.50" -> "20240927_night"
    std::string data_format(std::string s);
    std::shared_ptr<rapidcsv::Document> doc_p;
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
        for (auto &i : frr)
        {
            delete i;
        }
        delete dcg;
        dcg = nullptr;
    }
    void setQuoteMsg(QuoteMsg &qm);
    void done();
    void begin();
};