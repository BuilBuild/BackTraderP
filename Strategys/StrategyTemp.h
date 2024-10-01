#pragma once

class StraTemplate
{

public:

    // 回调函数
    virtual void on_init(int i) = 0;
    virtual void on_session_begin(double uTDate) = 0;
    virtual void on_session_end(double uTDate) = 0;
    virtual void on_bar() = 0;
    virtual bool on_schedule(double curTime) = 0;
    /*
     *	回测结束事件
     *	只在回测下才会触发
     */
    virtual void on_end() {};
};