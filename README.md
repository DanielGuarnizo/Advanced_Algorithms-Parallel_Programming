
---

# C++ Debugging Environment Setup for macOS in VS Code

This guide provides a step-by-step process to configure a professional C++ debugging environment on macOS using Visual Studio Code. This setup allows you to compile and debug any C++ file with a single press of the `F5` key.

## Prerequisites

1.  **Visual Studio Code:** Must be installed.
2.  **VS Code C/C++ Extension:** The official [C/C++ extension pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) from Microsoft must be installed.

## Step 1: Install Xcode Command Line Tools

macOS does not include a C++ compiler by default. The easiest way to install one is by getting Apple's official command-line tools, which include the `clang++` compiler and the `lldb` debugger.

1.  Open the **Terminal** application.
2.  Run the following command:
    ```bash
    xcode-select --install
    ```
3.  A dialog box will appear. Click **"Install"** and agree to the license terms. This will download and install the necessary tools.

4.  To verify the installation, run this command in your terminal. You should see version information for Apple's `clang` compiler.
    ```bash
    clang++ --version
    ```

## Step 2: Project Setup in VS Code

1.  Open your main project folder in VS Code. For this project, that folder is `AAPP`.
    > **File > Open Folder... >** Select your `AAPP` directory.

2.  This will create a `.vscode` directory inside `AAPP` to store the following configuration files.

## Step 3: Configure the Build Task (`tasks.json`)

This file tells VS Code how to compile your active C++ file using `clang++`.

1.  In VS Code, open the Command Palette (`Cmd+Shift+P`).
2.  Type `Tasks: Configure Default Build Task` and press Enter.
3.  Select `C/C++: clang++ build active file` from the list.
4.  VS Code will create a `.vscode/tasks.json` file. Replace its entire contents with the following:

    ```json
    {
        "version": "2.0.0",
        "tasks": [
            {
                "label": "C/C++: clang++ build active file",
                "type": "shell",
                "command": "/usr/bin/clang++",
                "args": [
                    "-std=c++17",
                    "-g",
                    "${file}",
                    "-o",
                    "${fileDirname}/${fileBasenameNoExtension}"
                ],
                "options": {
                    "cwd": "${workspaceFolder}"
                },
                "problemMatcher": ["$gcc"],
                "group": {
                    "kind": "build",
                    "isDefault": true
                }
            }
        ]
    }
    ```

## Step 4: Configure the Debugger (`launch.json`)

This file tells VS Code how to launch the `lldb` debugger for your compiled program.

1.  Go to the **Run and Debug** view in the sidebar (`Cmd+Shift+D`).
2.  Click the link **"create a launch.json file"** and select **`C++ (GDB/LLDB)`**.
3.  VS Code will create a `.vscode/launch.json` file. Replace its entire contents with the following:

    ```json
    {
        "version": "0.2.0",
        "configurations": [
            {
                "name": "(lldb) Build and Debug Active File",
                "type": "cppdbg",
                "request": "launch",
                "program": "${fileDirname}/${fileBasenameNoExtension}",
                "args": [],
                "stopAtEntry": false,
                "cwd": "${fileDirname}",
                "environment": [],
                "externalConsole": false,
                "MIMode": "lldb",
                "preLaunchTask": "C/C++: clang++ build active file"
            }
        ]
    }
    ```

## How to Debug Your Code (Daily Workflow)

With the one-time setup complete, debugging any C++ file is now simple.

1.  **Open the C++ file** you want to debug.
2.  **Set a breakpoint** by clicking in the gutter to the left of a line number. A red dot will appear.
3.  **(Optional) Add Command-Line Arguments:** If your program needs arguments (like our sorting algorithm), add them to the `"args": []` array in the `.vscode/launch.json` file.
    *Example:*
    ```json
    "args": ["8", "2", "4", "9", "3", "6"],
    ```
4.  **Press `F5`** to start debugging.

VS Code will automatically compile your file, run the executable with your specified arguments, and pause execution at your breakpoint, allowing you to inspect variables and control the program flow.