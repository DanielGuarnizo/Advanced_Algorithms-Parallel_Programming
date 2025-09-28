#include <iostream>
#include <vector>
#include <string>
#include <stdexcept> // For std::stoi exception handling

/**
 * @brief Sorts a vector of any comparable type using the Insertion Sort algorithm.
 * @tparam T The type of elements in the vector.
 * @param arr The vector to be sorted (passed by reference).
 */
template <typename T>
void insertionSort(std::vector<T>& arr) {
    if (arr.size() <= 1) return;

    for (size_t i = 1; i < arr.size(); ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/**
 * @brief Helper function to print a vector's contents.
 */
template <typename T>
void printVector(const std::string& title, const std::vector<T>& arr) {
    std::cout << title;
    for (const T& val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Main entry point. Parses command-line arguments into a vector of integers.
 */
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <num1> <num2> <num3> ..." << std::endl;
        return 1; // Indicate error
    }

    std::vector<int> numbers;
    // Start from 1 to skip the program name (argv[0])
    for (int i = 1; i < argc; ++i) {
        try {
            numbers.push_back(std::stoi(argv[i]));
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid number '" << argv[i] << "'. Please provide only integers." << std::endl;
            return 1;
        }
    }

    printVector("Original vector: ", numbers);
    insertionSort(numbers);
    printVector("Sorted vector:   ", numbers);

    return 0; // Indicate success
}