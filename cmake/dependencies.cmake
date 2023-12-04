include(FetchContent)

FetchContent_Declare(
    adizzle
    GIT_REPOSITORY https://github.com/adamdusty/adizzle.git
    GIT_TAG        main
    GIT_SHALLOW    TRUE
    SYSTEM
)
FetchContent_MakeAvailable(adizzle)