cmake_minimum_required(VERSION 3.14)

project(CMake_variable_to_code LANGUAGES CXX C DESCRIPTION "export CMake variable to C++ code example" VERSION 1.0.0.0)

# Configure a header file to pass global variables
configure_file(GlobVarConfig.h.in GlobVarConfig.h)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(${PROJECT_NAME}
  main.cpp
)

target_include_directories( ${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${PROJECT_BINARY_DIR}"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt::Core
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
