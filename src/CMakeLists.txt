cmake_minimum_required(VERSION 3.14)

project(CMake_variable_to_code LANGUAGES CXX C DESCRIPTION "export CMake variable to C++ code example" VERSION 1.0.0.0)

add_compile_definitions(MYPROJECT_NAME=${PROJECT_NAME})
add_compile_definitions(MYPROJECT_DESCRIPTION=${PROJECT_DESCRIPTION})
add_compile_definitions(CMAKE_PROJECT_VERSION=${CMAKE_PROJECT_VERSION})

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(${PROJECT_NAME}
  main.cpp main.h
)

target_include_directories( ${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt::Core
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
