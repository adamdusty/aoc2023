cmake_minimum_required(VERSION 3.27)

project(
    aoc2023
    VERSION 0.1.0
    DESCRIPTION "A short description"
    LANGUAGES CXX
)

# Include utilities
include(cmake/options.cmake)
include(cmake/warning-guard.cmake)
include(cmake/compile-options.cmake)
include(cmake/dependencies.cmake)

# Declare library
add_library(aoc2023_aoc2023)
add_library(aoc2023::aoc2023 ALIAS aoc2023_aoc2023)

# Add sources
target_sources(aoc2023_aoc2023 PRIVATE
    src/aoc2023.cpp
)

# Add include directory
# warning_guard adds SYSTEM modifier if the project isn't top level
target_include_directories(
    aoc2023_aoc2023 ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

# Include and link dependencies
#target_link_libraries(aoc2023_aoc2023)

# Add compile options
add_dev_compile_opts(aoc2023_aoc2023)

# Generate header for export
include(GenerateExportHeader)
generate_export_header(
    aoc2023_aoc2023
    BASE_NAME aoc2023
    EXPORT_FILE_NAME include/aoc2023/export.hpp
    CUSTOM_CONTENT_FROM_VARIABLE pragma_suppress_c4251
)

# Set properties
set_target_properties(
    aoc2023_aoc2023 PROPERTIES
    CXX_VISIBILITY_PRESET "hidden"
    VISIBILITY_INLINES_HIDDEN YES
    VERSION "${PROJECT_VERSION}"
    SOVERSION "${PROJECT_VERSION_MAJOR}"
    EXPORT_NAME aoc2023
    OUTPUT_NAME aoc2023
)

# Install rules
if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# Enable testing
if(AOC2023_BUILD_TESTS)
    include(CTest)
    add_subdirectory(tests)
endif()