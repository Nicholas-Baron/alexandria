cmake_minimum_required(VERSION 3.0)
project(alexandria)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

set(WARNING_FLAGS "-Wall -Wextra -Wpedantic -Wmissing-declarations")

# Setup global flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNING_FLAGS} -fno-exceptions -fno-rtti -ffunction-sections")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g -fsantize=undefined")

# For clang-format support
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(ClangFormat)
file(GLOB to_be_formatted "test/*.cpp" "include/*.h" "src/*.cpp")
clangformat_setup(${to_be_formatted})

add_library(alexandria 
    src/ascii_string.cpp
    src/file_input.cpp
    src/global_mem.cpp
)

target_include_directories(alexandria PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(alexandria PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    )
target_compile_features(alexandria 
    PRIVATE cxx_auto_type 
    PUBLIC cxx_noexcept cxx_final cxx_attributes cxx_nullptr cxx_defaulted_functions cxx_constexpr
    )
# Alexandria should not need the C++ standard library.
target_compile_options(alexandria PRIVATE -nostdlib)

function(add_alexandria_test test_exec test_src)
    message(STATUS "Test ${test_exec} registered")
    add_executable(${test_exec} ${test_src})
    target_link_libraries(${test_exec} PRIVATE ubsan alexandria)
    target_compile_features(${test_exec} PRIVATE cxx_std_20)
    target_include_directories(${test_exec} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/external)
endfunction()

file(GLOB tests "test/*.cpp")
foreach(test_src ${tests})
    # find the last space
    string(FIND ${test_src} "/" slash_loc REVERSE)

    # substring out the filename
    string(SUBSTRING ${test_src} ${slash_loc} -1 test_exec)

    # remove the ".cpp" and initial "/"
    string(REGEX MATCH "[^./]+" test_exec ${test_exec})

    add_alexandria_test(${test_exec} ${test_src})

endforeach()
