#pragma once

#include "DataPar.h"

class HistoryReplayer
{
    DataPar *dp;
    HistoryReplayer(DataPar *);

public:
    void done();
};