cmake_minimum_required(VERSION 3.8)

file (GLOB SecureHashAlgorithmSources
    ${CMAKE_CURRENT_SOURCE_DIR}/src/SecureHashAlgorithm/SecureHashAlgorithm.cpp
)

add_library (SecureHashAlgorithm
    SHARED
        ${SecureHashAlgorithmSources}
)

target_include_directories(SecureHashAlgorithm
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Compression
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Scheduler
)

target_compile_options(SecureHashAlgorithm
    PRIVATE
        -fPIC
        -g
        -std=c++11
        -Wall
        -Werror
)

target_link_libraries(SecureHashAlgorithm
    PRIVATE
        Scheduler
        Compression
)
