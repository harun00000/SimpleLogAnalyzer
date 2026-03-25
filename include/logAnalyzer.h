#ifndef LOGANALYZER_H
#define LOGANALYZER_H

#include <string>
#include <vector>
#include <cstddef>
#include <fstream>
#include <iostream>

struct LogRecord
{
    std::string level;
    std::string message;
};

bool parseRow(const std::string& row, LogRecord& out);
std::vector<LogRecord> parseAllRows(const std::vector<std::string>& rows, std::vector<std::string>& badRows);
std::vector<std::string> readFile(const std::string& filename);
size_t countLevel(const std::vector<LogRecord>& records, const std::string& level);
void printStatistic(const std::vector<LogRecord>& records,const std::vector<std::string>& badRows);

#endif // LOGANALYZER_H
