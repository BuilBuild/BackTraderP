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
    double Price;
    double High;
    double Low;
    double Open;
    double Close;
    uint64_t sTime;
    uint64_t eTime;
} BarType;

typedef std::vector<BarType> VecBar;

typedef std::map<std::string, VecBar> DataM;




