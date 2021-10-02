cmake_minimum_required(VERSION 3.8)

file (GLOB BinaryOperatorsSources
    ${CMAKE_CURRENT_SOURCE_DIR}/src/BinaryOperators/BinaryOperators.cpp
)

add_library (BinaryOperators
    SHARED
        ${BinaryOperatorsSources}
)

target_compile_options(BinaryOperators
    PRIVATE
        -fPIC
        -g
        -std=c++11
        -Wall
        -Werror
)
