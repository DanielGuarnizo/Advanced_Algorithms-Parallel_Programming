#pragma once
#include <vector>
#include <stdexcept>

class Solution {
public:
    std::vector<int> run(const std::vector<std::vector<int>>& matrix, const std::vector<int>& vec) {
        // --- Validation ---
        if (matrix.empty() || vec.empty()) {
            throw std::runtime_error("Input matrix or vector cannot be empty.");
        }
        size_t matrix_cols = matrix[0].size();
        if (matrix_cols != vec.size()) {
            throw std::runtime_error("Matrix column count must equal vector size.");
        }
        
        size_t matrix_rows = matrix.size();
        
        // --- Algorithm Logic ---
        // Initialize the result vector with the correct size (number of rows) and default value 0.
        std::vector<int> result(matrix_rows, 0);

        // Iterate through each row of the matrix
        for (size_t i = 0; i < matrix_rows; ++i) {
            // Calculate the dot product of the current matrix row and the vector
            for (size_t j = 0; j < matrix_cols; ++j) {
                result[i] += matrix[i][j] * vec[j];
            }
        }
        
        return result;
    }
};