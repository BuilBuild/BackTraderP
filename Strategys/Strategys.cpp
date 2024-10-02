#include "Strategys.h"
#include <iostream>

void SelfStragtegyTest::on_init(int id)
{
    id = id;
}

void SelfStragtegyTest::on_session_begin(double uTDate)
{
}

void SelfStragtegyTest::on_session_end(double uTDate)
{
}

void SelfStragtegyTest::on_bar(BarType *b)
{
    bar_count ++;
    if(bar_count>2)
    {
        std::cout << "bar_now time is  " << b->eTime << std::endl;
        std::cout <<"bar_pre time is  "<< "  time:  " << b->eTime << std::endl;;
    }
}

bool SelfStragtegyTest::on_schedule(double curTime)
{
    std::cout << curTime << std::endl;
    return false;
}
