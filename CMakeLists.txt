cmake_minimum_required(VERSION 3.16)
project(LogAnalyzer)

set(CMAKE_CXX_STANDARD 17)

# library
add_library(log_analyzer
    src/logAnalyzer.cpp
)

target_include_directories(log_analyzer PUBLIC include)

add_executable(analyzer app/main.cpp)
target_link_libraries(analyzer log_analyzer)

option(BUILD_TESTS "Enable tests" ON)

if(BUILD_TESTS)
    include(FetchContent)

    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0
    )

    FetchContent_MakeAvailable(Catch2)

    enable_testing()

    add_executable(tests tests/test_log_analyzer.cpp)
    target_link_libraries(tests log_analyzer Catch2::Catch2WithMain)

    add_test(NAME tests COMMAND tests)
endif()