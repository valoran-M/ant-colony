cmake_minimum_required(VERSION 3.0)

project(ant-colony VERSION 0.0.1)

# Prepare doctest for other targets to use
find_package(doctest REQUIRED)
include(doctest)

set(SRCS
    src/controllers/manager.cpp
    src/controllers/initialize.cpp
    
    src/models/ant.cpp
    src/models/case.cpp
    src/models/colony.cpp
    src/models/coordinate.cpp
    src/models/data.cpp
    src/models/grid.cpp


    src/views/display.cpp
)

set(HEADERS
    src/controllers/manager.hpp

    src/models/ant.hpp
    src/models/case.hpp
    src/models/colony.hpp
    src/models/coordinate.hpp
    src/models/data.hpp
    src/models/grid.hpp

    src/views/display.hpp
)

set(TESTS
    tests/tests.cpp

    tests/models/ant.cpp
    tests/models/case.cpp
    tests/models/coordinate.cpp
)

set(LIBS
    SDL2
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