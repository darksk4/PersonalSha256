cmake_minimum_required(VERSION 3.8)

include(${CMAKE_CURRENT_SOURCE_DIR}/src/BinaryOperators/BinaryOperators.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/src/Scheduler/Scheduler.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/src/Compression/Compression.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/src/SecureHashAlgorithm/SecureHashAlgorithm.cmake)

add_executable(execute ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_dependencies(Compression Scheduler)
add_dependencies(execute Compression)


set(BinaryOperatorsLibrary BinaryOperators)
set(SchedulerLibrary Scheduler)
set(CompressionLibrary Compression)
set(SecureHashAlgorithmLirary SecureHashAlgorithm)

target_include_directories(execute
    PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(execute
    PRIVATE
        -std=c++11
        -g
        -Wall
        -Werror
)

target_link_libraries(execute
    PRIVATE
        ${BinaryOperatorsLibrary}
        ${SchedulerLibrary}
        ${CompressionLibrary}
        ${SecureHashAlgorithmLirary}
)
