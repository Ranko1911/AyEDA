# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Algoritmos y Estructuras de Datos Avanzados
#
# @author José Javier Ramos Carballo
# @date 30 Mar 2023
# @brief CMakeLists.txt example
# CMakeLists.txt defines the whole build
# CMake reads CMakeLists.txt sequentially
#
# Build process:
#   1. cd <project_folder>
#   2. mkdir build
#   3. cd build
#   4. cmake ..
#   5. make


cmake_minimum_required(VERSION 3.1)  # Mandatory

# set the project name 
project(hash_table_main              # Mandatory
    VERSION 1.0
    DESCRIPTION "hash_table_main"
    LANGUAGES CXX)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 14) 						# Use c++14
set(CMAKE_CXX_STANDARD_REQUIRED True)

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(hash_table_main
    src/block.h
    src/dispersion_function_module.h
    src/dispersion_function_pseudorandom.h
    src/dispersion_function_sum.h
    src/dispersion_function.h
    src/exploration_function_double.h
    src/exploration_function_lineal.h
    src/exploration_function_quadratic.h
    src/exploration_function_redispersion.h
    src/exploration_function.h
    src/hash_table_main.cc
    src/hash_table.h
    src/list.h
    src/sequence.h
    src/vehicle.h)
