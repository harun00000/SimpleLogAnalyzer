#include "logAnalyzer.h"

bool parseRow(const std::string& row, LogRecord& out)
{
    if (row.empty()) return false;
    if (row[0] != '[') return false;

    size_t idx = 1;

    while (idx < row.size() && row[idx] != ']')
    {
        idx++;
    }

    if (idx == row.size()) return false;

    out.level = row.substr(1, idx - 1);

    if (idx + 2 > row.size()) return false;
    if (row[idx + 1] != ' ') return false;

    out.message = row.substr(idx + 2);

    if (out.message.empty()) return false;

    return true;
}

std::vector<LogRecord> parseAllRows(const std::vector<std::string>& rows, std::vector<std::string>& badRows)
{
    std::vector<LogRecord> records{};

    for (size_t i = 0; i < rows.size(); ++i)
    {
        LogRecord record{};

        if (parseRow(rows[i], record))
            records.push_back(record);
        else
            badRows.push_back(rows[i]);
    }

    return records;
}

std::vector<std::string> readFile(const std::string& filename)
{
    std::vector<std::string> rows{};

    std::ifstream file(filename);

    if (!file.is_open())
        return rows;

    std::string row{};

    while (std::getline(file, row))
    {
        rows.push_back(row);
    }

    return rows;
}

size_t countLevel(const std::vector<LogRecord>& records, const std::string& level)
{
    size_t count = 0;

    for (size_t i = 0; i < records.size(); ++i)
    {
        if (records[i].level == level)
            count++;
    }

    return count;
}

void printStatistic(const std::vector<LogRecord>& records, const std::vector<std::string>& badRows)
{
    std::cout << "INFO: "    << countLevel(records, "INFO")    << "\n";
    std::cout << "WARNING: " << countLevel(records, "WARNING") << "\n";
    std::cout << "ERROR: "   << countLevel(records, "ERROR")   << "\n";
    std::cout << "BAD: "     << badRows.size()                 << "\n";
}
