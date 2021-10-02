cmake_minimum_required(VERSION 3.8)

file (GLOB CompressionSources
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Compression/Compression.cpp
)

add_library (Compression
    SHARED
        ${CompressionSources}
)

target_include_directories(Compression
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/BinaryOperators
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Scheduler
)

target_compile_options(Compression
    PRIVATE
        -fPIC
        -g
        -std=c++11
        -Wall
        -Werror
)

target_link_libraries(Compression
    PRIVATE
        BinaryOperators
        Scheduler
)
