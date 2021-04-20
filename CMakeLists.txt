cmake_minimum_required(VERSION 3.0)

project(ant-colony VERSION 0.0.1)

# Prepare doctest for other targets to use
find_package(doctest REQUIRED)
include(doctest)

set(SRCS
    
)

set(HEADERS
    
)

set(TESTS
    tests/tests.cpp
)

set(LIBS
    
)

add_executable(ant_sim src/main.cpp ${SRCS} ${HEADERS})
target_compile_features(ant_sim PRIVATE cxx_std_17)
target_include_directories(ant_sim PUBLIC src/)
target_link_libraries(ant_sim ${LIBS})

# Make test executable

# tests
add_executable(run_tests ${TESTS} ${SRCS} ${HEADERS})
target_compile_features(run_tests PRIVATE cxx_std_17)
target_include_directories(run_tests PUBLIC src/)
target_link_libraries(run_tests PRIVATE doctest::doctest ${LIBS})