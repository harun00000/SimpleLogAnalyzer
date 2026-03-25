#include "logAnalyzer.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("parseRow")
{
    LogRecord rec{};

    REQUIRE(parseRow("[INFO] hi", rec));
    REQUIRE_FALSE(parseRow("[INFO]NoSpace", rec));
}

TEST_CASE("parseAllRows")
{
    std::vector<std::string> rows = {
        "[INFO] ok",
        "trash"
    };

    std::vector<std::string> bad{};
    auto rec = parseAllRows(rows, bad);

    REQUIRE(rec.size() == 1);
    REQUIRE(bad.size() == 1);
}

TEST_CASE("countLevel")
{
    std::vector<LogRecord> records = {
        {"INFO", "a"},
        {"ERROR", "b"},
        {"INFO", "c"}
    };

    REQUIRE(countLevel(records, "INFO") == 2);
}

TEST_CASE("parseRow edge cases")
{
    LogRecord rec{};

    REQUIRE_FALSE(parseRow("", rec));
    REQUIRE_FALSE(parseRow("[ERROR]", rec));
}

TEST_CASE("countLevel empty input")
{
    std::vector<LogRecord> records{};

    REQUIRE(countLevel(records, "INFO") == 0);
}

TEST_CASE("parseRow unknown level")
{
    LogRecord rec{};

    REQUIRE(parseRow("[GANGSTA] msg", rec));
}
