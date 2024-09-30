#include <iostream>
#include <chrono>
#include <ctime>
 
int main() {
    std::time_t;
    std::tm time_elements = {};
    time_elements.tm_year = 2050 - 1900; // 年份从 1900 开始
    time_elements.tm_mon = 1; // 1 月
    time_elements.tm_mday = 1; // 1 日
    // ... 设置其他时间元素
 
    // 使用 std::chrono 来处理可能的溢出问题
    auto tp = std::chrono::system_clock::from_time_t(0)
              + std::chrono::hours(time_elements.tm_hour)
              + std::chrono::minutes(time_elements.tm_min)
              + std::chrono::seconds(time_elements.tm_sec);
 
    // 如果需要，可以将 std::chrono::time_point 转换回 time_t 或 tm
    std::time_t time_since_epoch = std::chrono::system_clock::to_time_t(tp);
    std::tm* gmt = std::gmtime(&time_since_epoch);
 
    std::cout << "Year: " << 1900 + gmt->tm_year << std::endl;
    // ... 输出其他时间元素
 
    return 0;
}