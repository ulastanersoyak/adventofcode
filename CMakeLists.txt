cmake_minimum_required(VERSION 3.22)

if (NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()

project(advent_of_code VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_COMPILER_IS_GNUCXX)
  add_compile_options(
    -Wall -Wextra -Wpedantic -Wunused -Wuninitialized -Wshadow -Wconversion -Wduplicated-cond -Wduplicated-branches
    -Wlogical-op -Wuseless-cast -Wsign-conversion -Wfloat-equal -Weffc++ -Wold-style-cast -Wvexing-parse -Wformat=2 -Wvla 
    -Wsuggest-override -Wsuggest-final-methods -Wsuggest-final-types -Wnon-virtual-dtor -Wctor-dtor-privacy)
endif()

if(CMAKE_BUILD_TYPE STREQUAL debug)
  add_compile_options(-g)
endif()

if(CMAKE_BUILD_TYPE STREQUAL fast)
  add_compile_options(-Ofast)
endif()

add_subdirectory(src)
