cmake_minimum_required(VERSION 3.0)

project(ant-colony VERSION 0.0.1)

set(SRCS
    src/controllers/ant.cpp
    src/controllers/initialize.cpp
    src/controllers/manager.cpp
    src/controllers/random.cpp
    src/controllers/simulation.cpp
    
    src/models/ant.cpp
    src/models/case.cpp
    src/models/colony.cpp
    src/models/coordinate.cpp
    src/models/data.cpp
    src/models/grid.cpp

    src/views/barrier.cpp
    src/views/display.cpp
    src/views/init.cpp
    src/views/event.cpp
    src/views/data.cpp
    src/views/menu.cpp
)

set(HEADERS
    src/controllers/manager.hpp
    src/controllers/random.hpp

    src/models/ant.hpp
    src/models/case.hpp
    src/models/colony.hpp
    src/models/coordinate.hpp
    src/models/data.hpp
    src/models/grid.hpp

    src/views/display.hpp
    src/views/menu.hpp
)

set(TESTS
    tests/tests.cpp

    tests/models/ant.cpp
    tests/models/case.cpp
    tests/models/coordinate.cpp
    tests/models/colony.cpp
    tests/models/data.cpp
    tests/models/grid.cpp
)

set(LIBS
    sfml-system
    sfml-graphics
    sfml-window
)

add_executable(ant_sim src/main.cpp ${SRCS} ${HEADERS})
target_compile_features(ant_sim PRIVATE cxx_std_17)
target_include_directories(ant_sim PUBLIC src/)
target_link_libraries(ant_sim ${LIBS})

# Make test executable

# tests
add_executable(run_tests ${TESTS} ${SRCS} ${HEADERS} tests/doctest.h)
target_compile_features(run_tests PRIVATE cxx_std_17)
target_include_directories(run_tests PUBLIC src/ tests/)
target_link_libraries(run_tests ${LIBS})
