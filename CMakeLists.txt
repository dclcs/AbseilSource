cmake_minimum_required(VERSION 3.10)

project(AbseilSource)

# Abseil requires C++14
set(CMAKE_CXX_STANDARD 14)

# Process Abseil's CMake build system
add_subdirectory(abseil-cpp)

add_executable(hello_world hello_world.cc
        toy-abseil/container/flat_hash_set.h
        toy-abseil/container/internal/raw_hash_set.h
        toy-abseil/container/internal/common_policy_traits.h
        toy-abseil/container/internal/hash_policy_traits.h
        toy-abseil/container/internal/compressed_tuple.h
        toy-abseil/utility/utility.h)

# Declare dependency on the absl::strings library
target_link_libraries(hello_world absl::strings absl::flat_hash_map absl::flat_hash_set)
add_executable(nonexceptExample cases/NoexpectCases.cpp)
add_executable(explicitCases cases/ExplicitCases.cpp)
add_executable(typeUseCase cases/TypeUseCases.cpp)
