#include "DataPar.h"
#include "rapidcsv.h"
#include<iostream>
#include <time.h>
#include<string.h>
#include<chrono>



double StimeToDoubleStamp(std::string st)
{
    struct tm tm{};
    std::string second_time = std::string(st.begin(),st.begin()+19);
    std::string mill_second = std::string(st.begin()+19, st.end());
    strptime(second_time.c_str(), "%Y-%m-%d %H:%M:%S",  &tm);
    double time_now = double(mktime(&tm))+std::stod(mill_second);
    return time_now;
}


DataPar::DataPar()
{
}

DataPar::DataPar(std::vector<std::string> futures, int peroid)
{
    for(auto a : futures)
    {
        // std::cout << a << std::endl;
        ;
    }
    readCSV("/home/leijiulong/git_project/BackTraderP/DataStore/csv/20240924_night/au2412_market_data.csv", peroid);
}

bool DataPar::readCSV(std::string path, int period)
{
    std::string futures_name = "";
    // std::string::reverse_iterator rbegin = path.rbegin();
    for(auto rbegin=path.rbegin();rbegin< path.rend(); rbegin++ )
    {
        // std::cout << *rbegin << std::endl;
        if(*rbegin == '/')
        {
            rbegin--;
            while(rbegin >= path.rbegin())
            {
                futures_name += *rbegin;
                rbegin--;
                if(*rbegin=='_')
                    break;
            }
            break;
        }
    }
    
    std::cout << futures_name << std::endl;
    if(dm.find(futures_name)==dm.end())
    {
        dm.insert(std::pair<std::string, VecBar>(futures_name, VecBar{}));
    }
    std::cout << &dm << std::endl;
    
    
    rapidcsv::Document doc(path, rapidcsv::LabelParams(0, 0));
    std::vector<int> Volume = doc.GetColumn<int>("Volume");
    std::vector<double> Price = doc.GetColumn<double>("LastPrice");
    std::vector<std::string> UpdateTime = doc.GetColumn<std::string>("UpdateTime");
    std::size_t size = Volume.size();
    std::cout << size << std::endl;

    int Vol = Volume[0];
    float Pri = Price[0];
    float Hi = Price[0];
    float Lo = Price[0];
    float Op = Price[0];
    float Cl = Price[0];
    std::string date = "2024-09-24 ";
    double sTime = StimeToDoubleStamp(date+ UpdateTime[0]);
    double eTime = StimeToDoubleStamp(date+ UpdateTime[0]);
    std::size_t pr_index= 0;
    std::cout.precision(17);
    int out_count = 0;
    BarType bt{};
    VecBar * vb = &(dm.find(futures_name)->second);
    std::cout << dm.find(futures_name)->second.size() << std::endl;
    for(std::size_t i=0; i< size-14700; i++)
    {
        double time_now = StimeToDoubleStamp(date + UpdateTime[i]);
        if((time_now-sTime)<0)
        {
            date = "2024-09-25 ";
            double time_now = StimeToDoubleStamp(date + UpdateTime[i]);
        }

        if((time_now - sTime)>=period)
        {
            Cl = Price[i];
            Op = Price[pr_index];
            Lo = Price[pr_index];
            Hi = Price[pr_index];
            eTime = time_now;
            Vol = Volume[i]-Volume[pr_index];
            for(std::size_t in = pr_index;in<=i; in++)
            {
                if(Hi<Price[i])
                {
                    Hi = Price[i];
                }
                if(Lo>Price[i])
                {
                    Lo = Price[i];
                }
            }
            // std::cout << ++out_count << std::endl;
            // std::cout << "begin time: " << UpdateTime[pr_index]<< "   " <<sTime << std::endl;
            // std::cout << "close: " << Cl << " Open: " << Op << " Hig: " << Hi 
            // << " Low: " << Lo << "  Volume: " << Vol <<std::endl;
            // std::cout << "end time: " << UpdateTime[i]  << "   " <<time_now << std::endl<< std::endl;
            vb->emplace_back(Vol, Pri, Hi, Lo, Op, Cl, sTime, time_now);
            pr_index = i;
            sTime = time_now;
        }
        // std::cout << futures_name << std::endl;
    }



    // std::cout << "  999999  "<< vb->size() << std::endl;
    return false;
}

bool DataPar::dataPush()
{
    return false;
}
