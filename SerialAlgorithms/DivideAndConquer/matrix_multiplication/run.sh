#!/bin/bash

# --- Configuration ---
CPP_SOURCE="main.cpp"
EXECUTABLE="runner"

# --- Test Case Configuration ---
# The arguments are the filenames for the matrix and the vector.
PROGRAM_ARGS=("matrix.txt" "vector.txt")


# --- Logic (No need to edit below this line) ---
# Compile the file if the executable doesn't exist or if the source is newer.
if [ ! -f "$EXECUTABLE" ] || [ "$CPP_SOURCE" -nt "$EXECUTABLE" ]; then
    echo "Compiling '$CPP_SOURCE' with clang++..."
    
    # THIS IS THE CRITICAL FIX:
    # We add the -I flag to tell clang++ where to find your include files.
    # "$(dirname "$0")/../../../include" is a robust way to find the AAPP/include folder.
    clang++ -std=c++17 -g -I"$(dirname "$0")/../../../include" -o "$EXECUTABLE" "$CPP_SOURCE"

    if [ $? -ne 0 ]; then
        echo "Compilation failed."
        exit 1
    fi
else
    echo "Executable '$EXECUTABLE' is up-to-date. Skipping compilation."
fi

# Run the compiled program, passing the array of arguments correctly.
echo "------------------------------------"
echo "Running './$EXECUTABLE' with arguments: ${PROGRAM_ARGS[@]}"
./"$EXECUTABLE" "${PROGRAM_ARGS[@]}"
echo "------------------------------------"