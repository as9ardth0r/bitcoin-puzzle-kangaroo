cmake_minimum_required(VERSION 3.18)
project(KangarooPuzzle71 LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_STANDARD 17)

# Support des architectures GPU NVIDIA récentes
if(NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
    set(CMAKE_CUDA_ARCHITECTURES 75 80 86 89 90)
endif()

# Flags d'optimisation
if(MSVC)
    add_compile_options(/O2 /arch:AVX2)
    set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -O3 -Xcompiler /O2")
else()
    add_compile_options(-O3 -march=native -mavx2 -pthread)
    set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -O3 -Xcompiler -O3,-mavx2")
endif()

include_directories(include)

add_executable(kangaroo_solver 
    src/main.cpp 
    src/kangaroo.cu
)

set_target_properties(kangaroo_solver PROPERTIES
    CUDA_SEPARATE_COMPILATION ON
)

find_package(Threads REQUIRED)
target_link_libraries(kangaroo_solver PRIVATE Threads::Threads)