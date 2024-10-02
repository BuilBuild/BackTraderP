#include "HistoryReplayer.h"
#include "iostream"

HistoryReplayer::HistoryReplayer()
{
}

void HistoryReplayer::addStrategy(StraTemplate *s)
{
    stragegys.push_back(s);
}

void HistoryReplayer::setDataPar(DataPar *df)
{
    dp = df;
}

void HistoryReplayer::done()
{
    if(dp->dm.find("au2412") != dp->dm.end())
    {
        VecBar * vb = &(dp->dm.find("au2412")->second);
        for(auto a : *vb)
        {
            for(auto s : stragegys)
            {
                s->on_bar(&a);
            }
        }
    }  
}