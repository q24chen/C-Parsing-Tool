# C-Parsing-Tool
A tool to analyze a C++ file, extracting all public functions and global declarations from the source file

## Build Instructions：
### Prerequisites:
Before you begin the build process, ensure that the following prerequisites are met:
#### LLVM Installation: 
Ensure that LLVM is installed on your system. LLVM provides the Clang-C API needed for the project. You can download LLVM from [LLVM DOWNLOAD PAGE](https://releases.llvm.org/download.html)
#### CMake Installation: 
Make sure CMake is installed. CMake is used to configure the build process.[CMAKE DOWNLOAD PAGE](https://cmake.org/download/) 


## Configuring the Project：
Open the CMakeLists.txt file in the root directory of the project and Locate the include_directories and link_directories directives. Replace the paths in these directives with the actual paths to the include and lib directories in your LLVM installation. These paths are where LLVM's headers and libraries are located.

## Building the Project:
Ensure you are in the root directory of the project where CMakeLists.txt is located.
```
cmake -B build
cd build
cmake --build .
```

## Running the Executable:
```
cd ..
.\build\Debug\analyze.exe
```
Replace Debug with the appropriate configuration if different.

