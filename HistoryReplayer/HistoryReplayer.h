#pragma once
#include <vector>
#include "DataPar.h"
#include "StrategyTemp.h"

class HistoryReplayer
{
public:
    DataPar *dp=nullptr;
    HistoryReplayer();
    void addStrategy(StraTemplate *);
    void setDataPar(DataPar *dp);

private:
    std::vector<StraTemplate*> stragegys{}; 
public:
    void done();
};