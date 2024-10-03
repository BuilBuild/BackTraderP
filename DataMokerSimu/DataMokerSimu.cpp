#include "DataMokerSimu.h"
#include "rapidcsv.h"
#include <time.h>
#include <regex>

DataMokerSimu::DataMokerSimu(std::string DataPath)
{
    dcg = new DataCSVGet(DataPath);
    dcg->dataDone();
}

void DataMokerSimu::setQuoteMsg(QuoteMsg &qm)
{
    quote_list = &qm.ql;

    for (auto &s : *quote_list)
    {
        std::cout << s << std::endl;
        auto it = dcg->data_map_list.find(s);
        if (it != dcg->data_map_list.end())
        {
            auto &v = it->second;
            FileReadRecoder *f = new FileReadRecoder(&v);
            f->period = qm.peroid;
            f->sTime = qm.sTime;
            f->eTime = qm.eTime;
            f->date_now = std::string(qm.sTime.begin(), qm.sTime.begin() + 10);
            tm tm{};
            std::string second_time = std::string(qm.sTime.begin(), qm.sTime.begin() + 19);
            std::string mill_second = std::string(qm.sTime.begin() + 19, qm.sTime.end());
            strptime(second_time.c_str(), "%Y-%m-%d %H:%M:%S", &tm);
            f->s_time = double(mktime(&tm)) + std::stod(mill_second);
            second_time = std::string(qm.eTime.begin(), qm.eTime.begin() + 19);
            mill_second = std::string(qm.eTime.begin() + 19, qm.eTime.end());
            strptime(second_time.c_str(), "%Y-%m-%d %H:%M:%S", &tm);
            f->e_time = double(mktime(&tm)) + std::stod(mill_second);

            std::cout.precision(17);
            std::cout << f->date_now << "  " << f->s_time << "   " << f->e_time << std::endl;
            frr.push_back(f);
        }
    }
}

void DataMokerSimu::done()
{
    for (auto i : frr)
    {
        std::cout << (*(i->data_file_list)).size() << std::endl;
        // for(auto i : *(i->data_file_list))
        // {
        //     std::cout << i << std::endl;
        // }
    }
}

void DataMokerSimu::begin()
{
    for (auto i : frr)
    {
        i->next();
    }
}

void FileReadRecoder::next()
{
    if (!prepared)
    {
        prepare();
    }
}

void FileReadRecoder::prepare()
{
    // 找到对应初始日期的地址
    std::cout << date_now << std::endl;
    // 先将开始日期进行转换
    auto data_dir = data_format(sTime);
    std::cout << "dir===" << data_dir << std::endl;

    // 进行正则匹配找到对应文件夹和目录
    // 如果找不到则找与该时间最近的滞后文件
    //  std::regex date_dir_reg(".*/" + data_dir + "/.*");
    std::regex date_dir_reg(R"(.*/([0-9]{8}_[a-z]{3,5})/.*)");
    bool ret = false;
    for (auto csv_path : *data_file_list)
    {
        std::smatch m;
        ret = std::regex_match(csv_path, m, date_dir_reg);

        if (ret)
        {
            std::cout << "find_the_file_path: " << csv_path << std::endl;
            for (auto &elem : m)
            {
                if(data_dir <=elem.str())
                {
                    std::cout << elem  << std::endl;
                    break;
                }
            }
            // if(data_dir <= elem)
            // std::cout << m.str() << std::endl;
            // std::cout << m.length() << std::endl;
            // std::cout << m.position() << std::endl;
        }
    }
    if (!ret)
    {
        std::cout << "cannot find the file path...." << std::endl;
    }
}

std::string FileReadRecoder::data_format(std::string s)
{
    std::string data{};
    for (auto it : s)
    {
        if (it == ' ')
        {
            break;
        }
        if (it != '-')
            data += it;
    }
    std::string day_or_night{};
    for (auto it = s.begin(); it != s.end(); ++it)
    {

        if (*it == ' ')
        {
            int hour_int = std::stoi(std::string(it + 1, it + 3));
            if (hour_int >= 6 || hour_int <= 21)
            {
                day_or_night = "_day";
            }
            else
            {
                day_or_night = "_night";
            }
            break;
        }
    }
    return data + day_or_night;
}
