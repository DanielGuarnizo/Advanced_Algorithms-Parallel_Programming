#!/bin/bash

# --- Configuration ---
# The name of your C++ source file
CPP_SOURCE="insert_sort_al.cpp"
# The desired name for the compiled executable
EXECUTABLE="insertion_sort_runner"

# --- Vector to be Sorted ---
# MODIFY THIS LINE to test different vectors.
# Numbers must be separated by spaces.
VECTOR_TO_SORT="7 8 2 4 9 3 6 11"


# --- Logic ---
# Check if the executable file does NOT exist (-f checks for a regular file)
if [ ! -f "$EXECUTABLE" ]; then
    echo "Executable '$EXECUTABLE' not found. Compiling..."
    # Compile the C++ file. The -o flag sets the output name.
    g++ -std=c++17 -g -o "$EXECUTABLE" "$CPP_SOURCE"
    # Check if compilation was successful
    if [ $? -ne 0 ]; then
        echo "Compilation failed. Please check your C++ code."
        exit 1
    fi
else
    echo "Executable '$EXECUTABLE' already exists. Skipping compilation."
fi

# Run the compiled program, passing the vector as command-line arguments.
# The shell automatically splits the string in VECTOR_TO_SORT by spaces.
echo "------------------------------------"
./"$EXECUTABLE" $VECTOR_TO_SORT
echo "------------------------------------"