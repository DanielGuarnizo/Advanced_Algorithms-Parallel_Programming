# #!/bin/bash

# # --- Configuration ---
# # The C++ source file to compile and run.
# CPP_SOURCE="insert_sort_al.cpp"
# # The desired name for the compiled executable.
# EXECUTABLE="insert_sort_al"

# # --- Vector to be Sorted ---
# # MODIFY THIS LINE to test different vectors.
# # Numbers must be separated by spaces.
# VECTOR_TO_SORT="7 8 2 4 9 3 6 11"


# # --- Logic ---
# # Check if the executable file does NOT exist.
# if [ ! -f "$EXECUTABLE" ]; then
#     echo "Executable '$EXECUTABLE' not found. Compiling with clang++..."
#     # On macOS, the native C++ compiler is clang++.
#     # The arguments are the same as for g++.
#     clang++ -std=c++17 -g -o "$EXECUTABLE" "$CPP_SOURCE"

#     # Check if compilation was successful.
#     if [ $? -ne 0 ]; then
#         echo "Compilation failed. Please check your C++ code."
#         exit 1
#     fi
# else
#     echo "Executable '$EXECUTABLE' already exists. Skipping compilation."
# fi

# # Run the compiled program, passing the vector as command-line arguments.
# echo "------------------------------------"
# ./"$EXECUTABLE" $VECTOR_TO_SORT
# echo "------------------------------------"


#!/bin/bash

# --- Configuration ---
# Standardized names for source and executable files. Do not change these.
CPP_SOURCE="main.cpp"
EXECUTABLE="runner"

# --- Test Case Configuration ---
# Define the command-line arguments for the program in this array.
# Each element in the parentheses is a separate argument.
# This is the ONLY section you need to modify for different test cases.

# Example for Insertion Sort:
PROGRAM_ARGS=("7" "8" "2" "4" "9" "3" "6" "11")

# Example for Matrix Multiplication (if it takes matrix dimensions):
# PROGRAM_ARGS=("3" "4" "5")

# Example for another algorithm (if it takes input/output filenames):
# PROGRAM_ARGS=("input.txt" "output.txt")


# --- Logic (No need to edit below this line) ---
# Compile the file if the executable doesn't exist or if the source is newer.
if [ ! -f "$EXECUTABLE" ] || [ "$CPP_SOURCE" -nt "$EXECUTABLE" ]; then
    echo "Compiling '$CPP_SOURCE' with clang++..."
    clang++ -std=c++17 -g -o "$EXECUTABLE" "$CPP_SOURCE"

    if [ $? -ne 0 ]; then
        echo "Compilation failed."
        exit 1
    fi
else
    echo "Executable '$EXECUTABLE' is up-to-date. Skipping compilation."
fi

# Run the compiled program, passing the array of arguments correctly.
echo "------------------------------------"
# The "${PROGRAM_ARGS[@]}" syntax correctly passes each array element as a separate argument.
echo "Running './$EXECUTABLE' with arguments: ${PROGRAM_ARGS[@]}"
./"$EXECUTABLE" "${PROGRAM_ARGS[@]}"
echo "------------------------------------"