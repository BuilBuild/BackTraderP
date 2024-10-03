#include<iostream>
#include<string>
#include "DataMokerSimu.h"

using std::string;
int main()
{

    string path = "/home/leijiulong/桌面/datastore";
    QuoteMsg qmsg{};
    qmsg.ql = {"au2410", "AP501", "CF501", "IF2409"};
    qmsg.sTime = "2024-09-10 09:10:30.50";
    qmsg.eTime = "2024-09-27 09:50:50.50";
    qmsg.peroid = 3.2;

    DataMokerSimu dms = DataMokerSimu(path);
    dms.setQuoteMsg(qmsg);
    dms.done();
    //开始进行模拟
    dms.begin();
    std::cout << "hello" << std::endl;
}