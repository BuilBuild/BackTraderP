#include<iostream>

#include "DataPar.h"
#include "HistoryReplayer.h"
#include "StrategyTemp.h"
#include"Strategys.h"


int main()
{

    // spdlog::init_thread_pool(10000, 1);
    // auto file_logger = spdlog::rotating_logger_mt<spdlog::async_factory>("file_logger", "mylogs", 1024 * 1024 * 5, 100);
    // int i = 0;
    // file_logger->set_level(spdlog::level::debug);
    // while (i < 1000000)
    // {
    //     file_logger->debug("Async message #{}", i);
    //     i++;
    // }
    // spdlog::drop_all();



    std::vector<std::string> a = {"nihao", "woshi"};
    DataPar dp = DataPar(a,6);
    HistoryReplayer historyReplayer = HistoryReplayer();
    SelfStragtegyTest strategy = SelfStragtegyTest();
    strategy.on_init(1);
    historyReplayer.addStrategy(&strategy);
    historyReplayer.setDataPar(&dp);
    historyReplayer.done();
    
    
    
    std::cout << "hello " << std::endl;


    return 0;
}