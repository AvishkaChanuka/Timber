cmake_minimum_required(VERSION 3.24)
project(Timber)

set(CMAKE_CXX_STANDARD 17)

add_executable(Timber main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/SDK/SFML/x64/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(D:/SDK/SFML/x64/SFML-2.5.1/include)
target_link_libraries(Timber sfml-system sfml-window sfml-graphics sfml-audio)