cmake_minimum_required(VERSION 3.15)
project(RuleOf5 LANGUAGES CXX)

# Use C++23 for <print> and other modern features
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create executable from the single source file
add_executable(RuleOf5 RuleOf5.cpp)

# Ensure the project root is available for includes (header is next to the source)
target_include_directories(RuleOf5 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Optional: if you are using MinGW/GNU toolchain on Windows, you can configure the generator
# Example build commands (from project root):
# mkdir build && cd build
# cmake -G "MinGW Makefiles" ..
# mingw32-make
# or
# cmake .. && cmake --build .
