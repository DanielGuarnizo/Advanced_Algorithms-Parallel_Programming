#include "solution.h"
#include "run_solution.h"

int main(int argc, char* argv[]) {
    // Declare the signature: TestRunner<Solution, ReturnType, Arg1Type, ...>
    TestRunner<Solution, std::vector<int>, std::vector<std::vector<int>>, std::vector<int>> runner;
    return runner.execute(argc, argv);
}