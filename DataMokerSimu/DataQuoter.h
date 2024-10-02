#pragma once
#include<vector>
#include<string>


class QuoterT
{
public:
    float period{};
    std::vector<std::string> *ql = nullptr;
    virtual void setQuter(const std::vector<std::string> &ql)=0
};