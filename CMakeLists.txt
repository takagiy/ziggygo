# Copyright (c) TakagiY 2019
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.8)

project(ziggygo
        VERSION 0.1.0
        LANGUAGES CXX)

option(REPORT_COVERAGE
       "Generate coverage.txt with clang and llvm-cov."
       OFF)

add_library(ziggygo INTERFACE)

add_library(ziggygo::ziggygo ALIAS ziggygo)

target_compile_features(ziggygo INTERFACE cxx_std_11)

target_include_directories(
    ziggygo
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
              $<INSTALL_INTERFACE:include>)


install(TARGETS ziggygo
        EXPORT ziggygo-config)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/ziggygo-config-version.cmake
    COMPATIBILITY SameMajorVersion)

install(EXPORT ziggygo-config
        NAMESPACE ziggygo::
        DESTINATION lib/cmake/ziggygo)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/ziggygo-config-version.cmake
        DESTINATION lib/cmake/ziggygo)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION include)

include(CTest)
    
add_subdirectory(test)
