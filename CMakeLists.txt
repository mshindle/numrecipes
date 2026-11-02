cmake_minimum_required(VERSION 3.16)

project(
    numrecipes
    VERSION 0.1.0
    DESCRIPTION "A small C library of numerical algorithms and utility routines"
    LANGUAGES C
)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_library(numrecipes
    src/misc.c
    src/linalg.c
    src/util.c
        src/matrix.c
)

add_library(numrecipes::numrecipes ALIAS numrecipes)

target_compile_features(numrecipes PUBLIC c_std_11)

target_include_directories(numrecipes
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

if(UNIX)
    target_link_libraries(numrecipes PUBLIC m)
endif()

set_target_properties(numrecipes
    PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
        PUBLIC_HEADER
            "include/numrecipes/misc.h;include/numrecipes/linalg.h;include/numrecipes/util.h;include/numrecipes/matrix.h"
)

install(
    TARGETS numrecipes
    EXPORT numrecipesTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/numrecipes
)

install(
    EXPORT numrecipesTargets
    FILE numrecipesTargets.cmake
    NAMESPACE numrecipes::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/numrecipes
)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/numrecipesConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/numrecipesConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/numrecipes
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/numrecipesConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/numrecipesConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/numrecipesConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/numrecipes
)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    option(NUMRECIPES_BUILD_TESTS "Build numrecipes unit tests" ON)
    option(NUMRECIPES_BUILD_EXAMPLES "Build numrecipes example programs" ON)
else()
    option(NUMRECIPES_BUILD_TESTS "Build numrecipes unit tests" OFF)
    option(NUMRECIPES_BUILD_EXAMPLES "Build numrecipes example programs" OFF)
endif()

if(NUMRECIPES_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(NUMRECIPES_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
