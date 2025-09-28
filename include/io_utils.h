#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>

// --- File Readers ---

// Reads a matrix from a text file.
std::vector<std::vector<int>> readMatrixFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open matrix file " + filename);
    }
    int rows, cols;
    file >> rows >> cols;
    if (file.fail() || rows <= 0 || cols <= 0) {
        throw std::runtime_error("Error: Invalid matrix dimensions in " + filename);
    }
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            file >> matrix[i][j];
            if (file.fail()) {
                throw std::runtime_error("Error: Mismatch between dimensions and data in " + filename);
            }
        }
    }
    file.close();
    return matrix;
}

// Reads a vector from a text file.
std::vector<int> readVectorFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open vector file " + filename);
    }
    int size;
    file >> size;
    if (file.fail() || size <= 0) {
        throw std::runtime_error("Error: Invalid vector size in " + filename);
    }
    std::vector<int> vec(size);
    for (int i = 0; i < size; ++i) {
        file >> vec[i];
        if (file.fail()) {
            throw std::runtime_error("Error: Mismatch between size and data in " + filename);
        }
    }
    file.close();
    return vec;
}


// --- Generic Result Printers ---
void printResult(const std::vector<int>& result) {
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

void printResult(int result) {
    std::cout << result << std::endl;
}

void printResult(bool result) {
    std::cout << (result ? "true" : "false") << std::endl;
}

void printResult(const std::string& result) {
    std::cout << result << std::endl;
}