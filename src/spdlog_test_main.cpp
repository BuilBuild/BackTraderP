#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/stopwatch.h"

void test_spd()
{
    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");

    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::debug("This message should be displayed..");

    // change log pattern
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

    // Compile time log levels
    // Note that this does not change the current log level, it will only
    // remove (depending on SPDLOG_ACTIVE_LEVEL) the call on the release code.
    SPDLOG_TRACE("Some trace message with param {}", 42);
    SPDLOG_DEBUG("Some debug message");
}

void stdout_example()
{
    // create a color multi-threaded logger
    auto console = spdlog::stdout_color_mt("console");
    auto err_logger = spdlog::stderr_color_mt("stderr");
    spdlog::get("console")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name)");
}

void basic_logfile_example()
{
    try
    {
        auto logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
        // auto t = logger.get("basic_logger");
    }
    catch (const spdlog::spdlog_ex &ex)
    {
        std::cout << "Log init failed: " << ex.what() << std::endl;
    }
}

void rotating_example()
{
    // Create a file rotating logger with 5 MB size max and 3 rotated files
    auto max_size = 1048576 * 5;
    auto max_files = 3;
    auto logger = spdlog::rotating_logger_mt("some_logger_name", "logs/rotating.txt", max_size, max_files);
}

int main()
{
    // test_spd();
    // stdout_example();
    // basic_logfile_example();
    spdlog::stopwatch sw; 
    rotating_example();
    spdlog::enable_backtrace(32); // Store the latest 32 messages in a buffer. 
    // or my_logger->enable_backtrace(32)..
    for(int i = 0; i < 100; i++)
    {
    spdlog::debug("Backtrace message {}", i); // not logged yet..
    }
    // e.g. if some error happened:
    spdlog::dump_backtrace(); // log them now! show the last 32 messages
    // or my_logger->dump_backtrace(32)..
    // periodically flush all *registered* loggers every 3 seconds:
// warning: only use if all your loggers are thread-safe ("_mt" loggers)
    spdlog::flush_every(std::chrono::seconds(3));
    return 0;
}