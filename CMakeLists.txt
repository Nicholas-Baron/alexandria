cmake_minimum_required(VERSION 3.0)
project(alexandria)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_FLAGS ${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g)

# For clang-format support
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(ClangFormat)
file(GLOB to_be_formatted "test/*.cpp" "include/*.h" "src/*.cpp")
clangformat_setup(${to_be_formatted})

add_library(alexandria 
    src/ascii_string.cpp
    src/global_mem.cpp
)

target_include_directories(alexandria PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(alexandria PRIVATE 
    ${CXX_FLAGS} -nostdlib -fno-exceptions -fno-rtti -fsanitize=undefined -Wmissing-declarations
)

file(GLOB tests "test/*.cpp")
foreach(test_src ${tests})
    # find the last space
    string(FIND ${test_src} "/" slash_loc REVERSE)

    # substring out the filename
    string(SUBSTRING ${test_src} ${slash_loc} -1 test_exec)

    # remove the ".cpp" and initial "/"
    string(REGEX MATCH "[^./]+" test_exec ${test_exec})

    message(STATUS "Test ${test_exec} registered")
    add_executable(${test_exec} ${test_src})
    target_link_libraries(${test_exec} PRIVATE ubsan alexandria)
    target_compile_options(${test_exec} PRIVATE 
        ${CXX_FLAGS} -nostdlib -fno-exceptions -fno-rtti -fsanitize=undefined
        )
    target_compile_features(${test_exec} PRIVATE cxx_std_20)
    target_include_directories(${test_exec} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/external)
endforeach()
