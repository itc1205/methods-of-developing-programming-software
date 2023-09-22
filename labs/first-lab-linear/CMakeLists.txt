cmake_minimum_required(VERSION 3.8)
project("first-lab-linear")

set(CXX_STANDARD C++17)

set(SOURCE
    src/main.cpp
)

add_executable(app ${SOURCE})

target_compile_features(app PRIVATE cxx_std_17)
