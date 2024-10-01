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
    std::cout << "history done" << std::endl;

    if(dp->dm.find("au2412") != dp->dm.end())
    {
        VecBar * vb = &(dp->dm.find("au2412")->second);
        int i = 0;
        for(auto a : *vb)
        {
            if(i>5)
                break;
            i++;
            for(auto s : stragegys)
            {
                s->on_schedule(a.eTime);
            }
            std::cout << a.Close << std::endl;
        }
    }  
}