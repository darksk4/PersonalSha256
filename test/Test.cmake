cmake_minimum_required(VERSION 3.8)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/googletest-release-1.10.0)


file (GLOB ActualTest
    ${CMAKE_CURRENT_SOURCE_DIR}/test/gtest_main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test/testcases/BinaryOperatorsTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test/testcases/SchedulerTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test/testcases/SecureHashAlgorithmTest.cpp
)

add_executable(test ${ActualTest})

add_dependencies(test execute)

target_include_directories(test
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/BinaryOperators
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Scheduler
        ${CMAKE_CURRENT_SOURCE_DIR}/src/SecureHashAlgorithm
)

target_link_libraries(test
    PUBLIC
        gtest
        ${BinaryOperatorsLibrary}
        ${SchedulerLibrary}
        ${SecureHashAlgorithmLirary}
)

target_compile_options(test
    PRIVATE
        -fPIC
        -std=c++11
        -g
        -Wall
        -Werror
        -Wextra
)
