cmake_minimum_required(VERSION 3.14...3.25)

project(
    cpp_template
    VERSION 0.1
    DESCRIPTION "A template for C++ projects."
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# external libraries
include(FetchContent)

# googletest
enable_testing()

include(GoogleTest)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# sfml
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)

# inireader
FetchContent_Declare(
    INIReader
    GIT_REPOSITORY https://github.com/jtilly/inih.git
)
FetchContent_MakeAvailable(INIReader)

# add subdirectories
add_subdirectory(apps)
add_subdirectory(src)
add_subdirectory(tests)
