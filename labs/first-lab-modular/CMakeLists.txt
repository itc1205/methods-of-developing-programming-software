cmake_minimum_required(VERSION 3.8)
project("first-lab-modular")

set(CXX_STANDARD C++17)

set(SOURCE
    src/main.cpp
    src/modules/database.cpp
    src/modules/repository.cpp
    src/modules/music_record.cpp
)

add_executable(app ${SOURCE})

target_compile_features(app PRIVATE cxx_std_17)