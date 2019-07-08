# Copyright (c) TakagiY 2019
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.8)

add_executable(test.out ${CMAKE_CURRENT_SOURCE_DIR}/src/test.cpp)

target_include_directories(
    test.out
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_BINARY_DIR}/external/catch/include)

target_link_libraries(test.out ziggygo::ziggygo)

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

add_dependencies(test.out catch)

add_test(NAME all_tests
         COMMAND $<TARGET_FILE:test.out>)

add_custom_target(check
                  COMMENT "Build and run all tests."
                  DEPENDS test.out
                  COMMAND ${CMAKE_CTEST_COMMAND})

if(REPORT_COVERAGE)
    if(NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        message(FATAL_ERROR
                "Option REPORT_COVERAGE currently only supports clang++.\n"
                "Please unset option REPORT_COVERAGE or set the compiler to clang++.\n"
                "(e.g. -DREPORT_COVERAGE=OFF or -DCMAKE_CXX_COMPILER=clang++)")
    endif()

    target_compile_options(
        test.out
        PRIVATE $<1:-fprofile-instr-generate
                    -fcoverage-mapping
                    -g>)

    target_link_options(
        test.out
        PRIVATE $<1:-fprofile-instr-generate
                    -fcoverage-mapping
                    -g>)

    add_custom_target(
        coverage.profraw
        DEPENDS test.out
        COMMAND LLVM_PROFILE_FILE=${PROJECT_BINARY_DIR}/coverage.profraw $<TARGET_FILE:test.out>)

    add_custom_target(
        coverage.profdata
        DEPENDS coverage.profraw
        COMMAND llvm-profdata merge ${PROJECT_BINARY_DIR}/coverage.profraw -output=${PROJECT_BINARY_DIR}/coverage.profdata)

    add_custom_target(
        coverage.txt
        COMMENT "Generate coverage.txt."
        DEPENDS coverage.profdata
        COMMAND llvm-cov show $<TARGET_FILE:test.out> -instr-profile=${PROJECT_BINARY_DIR}/coverage.profdata > ${PROJECT_BINARY_DIR}/coverage.txt)
endif()
