cmake_minimum_required (VERSION 3.5)

project(math-homework)

set(CMAKE_CXX_STANDARD 11)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_subdirectory(src)

add_executable(test_permute test.cpp)

target_link_libraries(test_permute permute)
