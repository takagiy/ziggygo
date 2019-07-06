# Copyright (c) TakagiY 2019
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.8)

include(ExternalProject)

ExternalProject_Add(
    catch
    URL https://github.com/catchorg/Catch2/releases/download/v2.9.1/catch.hpp
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/external/catch
    DOWNLOAD_DIR ${CMAKE_CURRENT_BINARY_DIR}/external/catch/include
    DOWNLOAD_NO_EXTRACT ON
    LOG_DOWNLOAD ON
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND "")

add_executable(test-command ${CMAKE_CURRENT_SOURCE_DIR}/src/test.cpp)

add_dependencies(test-command catch)

target_include_directories(
    test-command
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_BINARY_DIR}/external/catch/include)

target_link_libraries(test-command ziggygo::ziggygo)

add_test(NAME all-tests
         COMMAND $<TARGET_FILE:test-command>)

add_custom_target(check
                  COMMENT "Build and run all tests."
                  DEPENDS test-command
                  COMMAND ${CMAKE_CTEST_COMMAND})
