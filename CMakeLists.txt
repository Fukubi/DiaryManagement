cmake_minimum_required(VERSION 3.16.3)

project(diarymanagement)

find_package(Curses REQUIRED)
add_library(libncurses STATIC IMPORTED)

add_executable(${PROJECT_NAME})

add_subdirectory(src)
add_subdirectory(lib)