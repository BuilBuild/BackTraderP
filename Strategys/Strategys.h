#pragma once
#include"StrategyTemp.h"

class SelfStragtegyTest : public StraTemplate
{
    int bar_count{};
    int id{};
public:
    SelfStragtegyTest(){};
    // 回调函数
    virtual void on_init(int id);
    virtual void on_session_begin(double uTDate);
    virtual void on_session_end(double uTDate);
    virtual void on_bar(BarType *);
    virtual bool on_schedule(double curTime);
    /*
     *	回测结束事件
     *	只在回测下才会触发
     */
    virtual void on_end() {};
};