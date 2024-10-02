#pragma once
#include "DataQuoter.h"

class MyQuoter: public QuoterT
{
public:
    MyQuoter();
    ~MyQuoter(){};
    virtual void setQuter(const std::vector<std::string> &ql) override;

};