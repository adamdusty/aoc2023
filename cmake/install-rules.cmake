if(PROJECT_IS_TOP_LEVEL)
  set(
      CMAKE_INSTALL_INCLUDEDIR "include/aoc2023-${PROJECT_VERSION}"
      CACHE PATH ""
  )
endif()

set(package aoc2023)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Set up export components
install(
    TARGETS aoc2023_aoc2023
    EXPORT aoc2023Targets
    RUNTIME COMPONENT aoc2023_Runtime
    LIBRARY COMPONENT aoc2023_Runtime
    NAMELINK_COMPONENT aoc2023_Development
    ARCHIVE COMPONENT aoc2023_Development
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Write package file for installations
write_basic_package_version_file(
    "${package}ConfigVersion.cmake"
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY SameMajorVersion
)

# Allow package maintainers to freely override the path for the configs
set(
    aoc2023_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/${package}"
    CACHE PATH "CMake package config location relative to the install prefix"
)
mark_as_advanced(aoc2023_INSTALL_CMAKEDIR)

# Install config file to the install directory
# Config file is used by find_package() (I assume)
install(
    FILES cmake/install-config.cmake
    DESTINATION "${aoc2023_INSTALL_CMAKEDIR}"
    RENAME "${package}Config.cmake"
    COMPONENT aoc2023_Development
)

# Install ConfigVersion file
# More package install info
install(
    FILES "${PROJECT_BINARY_DIR}/${package}ConfigVersion.cmake"
    DESTINATION "${aoc2023_INSTALL_CMAKEDIR}"
    COMPONENT aoc2023_Development
)

# Install the dev component from targets defined above (I think)
install(
    EXPORT aoc2023Targets
    NAMESPACE aoc2023::
    DESTINATION "${aoc2023_INSTALL_CMAKEDIR}"
    COMPONENT aoc2023_Development
)

# Include CPack
if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()