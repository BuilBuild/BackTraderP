#include "DataPar.h"
#include "rapidcsv.h"
#include<iostream>
#include <time.h>
#include<string.h>



double StimeToDoubleStamp(std::string st)
{
    struct tm tm;
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
    readCSV("/home/leijiulong/git_project/BackTraderP/DataStore/csv/20240924_night/au2412_market_data.csv");
}

bool DataPar::readCSV(std::string path)
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
    // double time_now = 
    std::size_t pr_index= 0;
    std::cout.precision(17);
    for(std::size_t i=0; i< size; i++)
    {
        // std::cout << sTime << std::endl;
        int period = 3;
        
        // std::cout << second_time << "  " << mill_second<<"   " << double(mktime(&tm))+std::stof(mill_second) <<std::endl;
        double time_now = StimeToDoubleStamp(date + UpdateTime[i]);

        // std::cout <<  time_now << std::endl;
        if((time_now-sTime)<0)
        {
            date = "2024-09-25 ";
            double time_now = StimeToDoubleStamp(date + UpdateTime[i]);
        }

        if((time_now - sTime)>3)
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
            std::cout << "begin time: " << UpdateTime[pr_index]<< "   " <<sTime << std::endl;
            std::cout << "close: " << Cl << " Open: " << Op \
            << " Low: " << Lo << "  Volume: " << Vol <<std::endl;
            std::cout << "end time: " << UpdateTime[i]  << "   " <<time_now << std::endl<< std::endl;
        }
        pr_index = i;
        sTime = time_now;
        // if(i >100)
        // {
        //     break;
        // }

    }

    return false;
}
