#pragma once

#include <bits/types.h>
#include <bits/timesize.h>
#include <cstdint>
#include <vector>
#include <map>
#include <string>
#include <string.h>



// typedef __uint8_t uint8_t;
// typedef __uint16_t uint16_t;
// typedef __uint32_t uint32_t;
// typedef __uint64_t uint64_t;


typedef struct BarType
{
    int Volume;
    float Price;
    float High;
    float Low;
    float Open;
    float Close;
    double sTime;
    double eTime;
} BarType;

typedef std::vector<BarType> VecBar;

typedef std::map<std::string, VecBar> DataM;




