#!/bin/bash

# --- Configuration ---
# The C++ source file to compile and run.
CPP_SOURCE="insert_sort_al.cpp"
# The desired name for the compiled executable.
EXECUTABLE="insert_sort_al"

# --- Vector to be Sorted ---
# MODIFY THIS LINE to test different vectors.
# Numbers must be separated by spaces.
VECTOR_TO_SORT="7 8 2 4 9 3 6 11"


# --- Logic ---
# Check if the executable file does NOT exist.
if [ ! -f "$EXECUTABLE" ]; then
    echo "Executable '$EXECUTABLE' not found. Compiling with clang++..."
    # On macOS, the native C++ compiler is clang++.
    # The arguments are the same as for g++.
    clang++ -std=c++17 -g -o "$EXECUTABLE" "$CPP_SOURCE"

    # Check if compilation was successful.
    if [ $? -ne 0 ]; then
        echo "Compilation failed. Please check your C++ code."
        exit 1
    fi
else
    echo "Executable '$EXECUTABLE' already exists. Skipping compilation."
fi

# Run the compiled program, passing the vector as command-line arguments.
echo "------------------------------------"
./"$EXECUTABLE" $VECTOR_TO_SORT
echo "------------------------------------"