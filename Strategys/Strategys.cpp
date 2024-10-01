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

void SelfStragtegyTest::on_bar()
{
}

bool SelfStragtegyTest::on_schedule(double curTime)
{
    std::cout << curTime << std::endl;
    return false;
}
