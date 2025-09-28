#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <functional>
#include "io_utils.h"

// Helper to convert command-line strings to specific types
class ArgParser {
    int argc;
    char** argv;
    int currentIndex = 1; // Start after program name

public:
    ArgParser(int ac, char** av) : argc(ac), argv(av) {}

    template <typename T>
    T getNext();
};

// Template specializations for each type we know how to parse
template<> int ArgParser::getNext<int>() {
    if (currentIndex >= argc) throw std::runtime_error("Not enough arguments for type 'int'");
    return std::stoi(argv[currentIndex++]);
}

template<> std::string ArgParser::getNext<std::string>() {
    if (currentIndex >= argc) throw std::runtime_error("Not enough arguments for type 'string'");
    return std::string(argv[currentIndex++]);
}

template<> std::vector<int> ArgParser::getNext<std::vector<int>>() {
    if (currentIndex >= argc) throw std::runtime_error("Not enough arguments for type 'vector<int>' (expected filename)");
    return readVectorFromFile(argv[currentIndex++]);
}

template<> std::vector<std::vector<int>> ArgParser::getNext<std::vector<std::vector<int>>>() {
    if (currentIndex >= argc) throw std::runtime_error("Not enough arguments for type 'vector<vector<int>>' (expected filename)");
    return readMatrixFromFile(argv[currentIndex++]);
}


// The generic TestRunner class
template <typename SolutionType, typename ReturnType, typename... Args>
class TestRunner {
public:
    int execute(int argc, char* argv[]) {
        try {
            SolutionType sol;
            ArgParser parser(argc, argv);
            
            // Create a tuple of arguments by parsing them one by one
            std::tuple<Args...> argsTuple = {parser.getNext<Args>()...};

            // Use std::apply to call the run method with the arguments from the tuple
            if constexpr (std::is_void_v<ReturnType>) {
                // Handle void return type
                std::apply([&](auto&&... args){ sol.run(args...); }, argsTuple);
                std::cout << "Execution finished." << std::endl;
            } else {
                // Handle non-void return types
                ReturnType result = std::apply([&](auto&&... args){ return sol.run(args...); }, argsTuple);
                std::cout << "Result: ";
                printResult(result); // Use our generic printer
            }
        } catch (const std::exception& e) {
            std::cerr << "An error occurred: " << e.what() << std::endl;
            return 1;
        }
        return 0;
    }
};