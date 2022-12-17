cmake_minimum_required(VERSION 3.14...3.25)

project(
    cpp_template
    VERSION 0.1
    DESCRIPTION "A template for C++ projects."
    LANGUAGES CXX
)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_EXTENSIONS ON)

    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()

add_subdirectory(apps)
add_subdirectory(src)
