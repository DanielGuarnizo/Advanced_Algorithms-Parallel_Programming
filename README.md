
---

# C++ Algorithm Development Framework

This project provides a simple, "LeetCode-style" framework for implementing and testing C++ algorithms. It separates your logic from the boilerplate, so you can focus on what matters.

## How it Works

-   **Algorithm Logic:** You write your code in a `solution.h` file.
-   **Test Runner:** A generic framework (`include/`) handles file reading, argument parsing, and printing results.
-   **Test Cases:** Each algorithm has its own `run.sh` script where you define the specific inputs for testing.

---

## How to Use This Repository

### Prerequisites

1.  **macOS:** With Xcode Command Line Tools installed (`xcode-select --install`).
2.  **Visual Studio Code:** With the official [C/C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools).

### Running an Existing Algorithm (from Terminal)

1.  Navigate to the algorithm's directory:
    ```bash
    cd SerialAlgorithms/DivideAndConquer/matrix_multiplication
    ```
2.  Run the test script:
    ```bash
    ./run.sh
    ```
    The script will compile the code and run it with the test case defined inside `run.sh`.

### Debugging an Existing Algorithm (in VS Code)

1.  **Open `solution.h`** for the algorithm you want to test and set a breakpoint.
2.  **Open `launch.json`** (`.vscode/launch.json`) and update the `"args"` array with the correct test inputs (e.g., `["matrix.txt", "vector.txt"]`).
3.  **IMPORTANT: Click on the `main.cpp` tab** in the algorithm's folder to make it the active file.
4.  Press **`F5`**.

The debugger will compile and stop at your breakpoint.

---


## How to Add a New Algorithm

Follow this pattern to add your own algorithms to the framework.

### Step 1: Create the Folder and Files

1.  Create a new folder for your algorithm (e.g., `my_new_algorithm`).
2.  Inside, create three files:
    -   `solution.h` (for your logic)
    -   `main.cpp` (to link to the framework)
    -   `run.sh` (for your test case)
3.  Add any necessary data files (e.g., `vector.txt`).

### Step 2: Implement Your Logic in `solution.h`

Write your code inside a `Solution` class.

```cpp
// my_new_algorithm/solution.h
#pragma once
#include <vector> // and any other headers you need

class Solution {
public:
    // Define your function with its specific inputs and return type.
    bool run(const std::vector<int>& nums, int k) {
        // ... your algorithm logic here ...
        return true;
    }
};
```

### Step 3: Link to the Framework in `main.cpp`

This tiny file tells the framework your function's signature.

```cpp
// my_new_algorithm/main.cpp
#include "solution.h"
#include "run_solution.h"

int main(int argc, char* argv[]) {
    // Declare the signature: TestRunner<Solution, ReturnType, Arg1Type, ...>
    TestRunner<Solution, bool, const std::vector<int>&, int> runner;
    return runner.execute(argc, argv);
}
```

### Step 4: Define a Test Case in `run.sh`

Copy this template and edit the `PROGRAM_ARGS` array with your test inputs.

```bash
#!/bin/bash
CPP_SOURCE="main.cpp"
EXECUTABLE="runner"

# --- Define Test Case Arguments ---
# List filenames, numbers, or strings for your test.
PROGRAM_ARGS=("vector.txt" "42")

# --- Logic (Do not edit) ---
if [ ! -f "$EXECUTABLE" ] || [ "$CPP_SOURCE" -nt "$EXECUTABLE" ]; then
    echo "Compiling '$CPP_SOURCE' with clang++..."
    clang++ -std=c++17 -g -I"$(dirname "$0")/../../../include" -o "$EXECUTABLE" "$CPP_SOURCE"
    if [ $? -ne 0 ]; then echo "Compilation failed."; exit 1; fi
fi
echo "------------------------------------"
./"$EXECUTABLE" "${PROGRAM_ARGS[@]}"
echo "------------------------------------"
```

You are now ready to run and debug your new algorithm using the steps at the top of this guide.