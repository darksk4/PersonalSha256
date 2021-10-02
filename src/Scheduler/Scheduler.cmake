cmake_minimum_required(VERSION 3.8)

file (GLOB SchedulerSources
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Scheduler/Scheduler.cpp
)

add_library (Scheduler
    SHARED
        ${SchedulerSources}
)

target_include_directories(Scheduler
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/BinaryOperators
)

target_compile_options(Scheduler
    PRIVATE
        -fPIC
        -g
        -std=c++11
        -Wall
        -Werror
)

target_link_libraries(Scheduler
    PRIVATE
        BinaryOperators
)
