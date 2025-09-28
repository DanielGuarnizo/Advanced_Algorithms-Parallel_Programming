#include "solution.h"
#include "run_solution.h"

int main(int argc, char* argv[]) {
    // The types here MUST be value types (no const&), matching the ArgParser.
    TestRunner<Solution, std::vector<int>, std::vector<std::vector<int>>, std::vector<int>> runner;
    return runner.execute(argc, argv);
}