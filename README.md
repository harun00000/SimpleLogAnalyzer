# SimpleLogAnalyzer

A simple C++ program for analyzing log files.

## Build

```bash
cmake -B build
cmake --build build
```

## Run

```bash
./build/analyzer sample.log
```

## Tests (optional)

Tests are disabled by default.

To enable and run tests:

```bash
cmake -B build -DBUILD_TESTS=ON
cmake --build build
cd build
ctest
```

## Input format

The program expects a plain text log file where each line starts with a log level:

```
INFO: message
WARNING: message
ERROR: message
```

## Example

Input file (`sample.log`):

```
INFO: Application started
WARNING: Low memory
ERROR: Failed to open file
INFO: Processing request
```

Output:

```
INFO: 2
WARNING: 1
ERROR: 1
```
