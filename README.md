This is export CMake variable to C++ code example. I also use Qt but it is not a main point. There are two ways: use [add_compile_definitions](https://cmake.org/cmake/help/latest/command/add_compile_definitions.html) or use [configure_file](https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html#exercise-3-adding-a-version-number-and-configured-header-file).
# add_compile_definitions way
1. Inside CMakeLists.txt any project has something like
```
project(CMake_variable_to_code LANGUAGES CXX C DESCRIPTION "export CMake variable to C++ code example" VERSION 1.0.0.0)
```
2. Somewhere inside CMakeLists.txt you should add
```
add_compile_definitions(MYPROJECT_NAME=${PROJECT_NAME})
add_compile_definitions(MYPROJECT_DESCRIPTION=${PROJECT_DESCRIPTION})
add_compile_definitions(CMAKE_PROJECT_VERSION=${CMAKE_PROJECT_VERSION})
```

3. Then in C++ code you should add
```
#define Q(x) #x
#define QUOTE(x) Q(x)
```

4. Now you can use CMake's variables inside C++ code. For example
```
QCoreApplication::setApplicationName(QUOTE(MYPROJECT_NAME));
QCoreApplication::setApplicationVersion(QUOTE(CMAKE_PROJECT_VERSION));
```

See also my feature [request](https://bugreports.qt.io/browse/QTBUG-123649) for Qt project.

## Compiling
```
git clone https://github.com/AndreiCherniaev/CMake_variable_to_code.git && cd "CMake_variable_to_code/add_compile_definitions_way"
rm -rf build-host && mkdir build-host/
cmake -S src/ -B build-host/
cmake --build build-host/ --parallel
```

## Test
```
build-host/CMake_variable_to_code --version
CMake_variable_to_code 1.0.0.0
```
```
build-host/CMake_variable_to_code --help
Usage: build-host/CMake_variable_to_code [options]
export CMake variable to C++ code example

Options:
  -h, --help     Displays help on commandline options.
  --help-all     Displays help, including generic Qt options.
  -v, --version  Displays version information.
```
