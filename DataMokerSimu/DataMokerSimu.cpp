#include "DataMokerSimu.h"
#include "rapidcsv.h"

DataMokerSimu::DataMokerSimu(std::string DataPath)
{
    dcg = new DataCSVGet(DataPath);
    dcg->dataDone();
}

void DataMokerSimu::setQuoteMsg(QuoteMsg &qm)
{
    quote_list = &qm.ql;
    
    for(auto &s: *quote_list)
    {
        std::cout << s << std::endl;
        auto it = dcg->data_map_list.find(s);
        if(it != dcg->data_map_list.end())
        {
            auto &v = it->second;
            FileReadRecoder *f = new FileReadRecoder(&v);
            frr.push_back(f);
            for(auto &pa : v)
            {
                std::cout << "--" << pa << std::endl;
            }
        }
    }
}

void DataMokerSimu::done()
{
    for(auto i : frr)
    {
        // std::cout << sizeof(i) << std::endl;
        std::cout << (*(i->data_file_list)).size()<< std::endl;
        for(auto i : *(i->data_file_list))
        {
            std::cout << i << std::endl;
        }
    }
    // for(auto it=quote_list->begin(); it != quote_list->end(); ++it)
    // {
    //     std::cout << *it << std::endl;
    // }
}
