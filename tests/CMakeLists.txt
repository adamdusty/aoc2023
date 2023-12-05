cmake_minimum_required(VERSION 3.27)

project(
    aoc2023Tests
    LANGUAGES CXX
)

# If test project is built independently, find the project package
if(PROJECT_IS_TOP_LEVEL)
    find_package(aoc2023 REQUIRED)
    enable_testing()
endif()

# Get the testing library
include(FetchContent)
FetchContent_Declare(
    snitch
    GIT_REPOSITORY https://github.com/cschreib/snitch.git
    GIT_TAG        v1.2.2
    GIT_SHALLOW    TRUE
    SYSTEM
    FIND_PACKAGE_ARGS # Use system package if installed
)
FetchContent_MakeAvailable(snitch)

# Add test exe
add_executable(aoc2023_tests)

# Add test sources
target_sources(aoc2023_tests PRIVATE
    src/d1.cpp
    src/d2.cpp
    src/d3.cpp
)

# Link libs
target_link_libraries(aoc2023_tests PRIVATE aoc2023::aoc2023 snitch::snitch)

# Add test
add_test(NAME aoc2023_tests COMMAND aoc2023_tests)

# Enable test binary to find the DLL if building a shared lib
if(BUILD_SHARED_LIBS)
    set_tests_properties(aoc2023_tests PROPERTIES
        ENVIRONMENT_MODIFICATION
            "PATH=path_list_append:$<TARGET_FILE_DIR:aoc2023::aoc2023>;PATH=path_list_append:$<TARGET_FILE_DIR:snitch::snitch>"
    )
endif()
