#include "logAnalyzer.h"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <logfile>\n";
        return EXIT_FAILURE;
    }

    std::string filename = argv[1];

    auto rows = readFile(filename);

    if (rows.empty())
    {
        std::cerr << "Error: cannot read file or file is empty.\n";
        return EXIT_FAILURE;
    }

    std::vector<std::string> bad{};
    auto records = parseAllRows(rows, bad);

    printStatistic(records, bad);

    return EXIT_SUCCESS;
}
