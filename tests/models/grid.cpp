#include "models/grid.hpp"
#include "doctest.h"

DOCTEST_TEST_SUITE_BEGIN("grid");

TEST_CASE("Constructor")
{
    Grid test = Grid();
    CHECK(test.width == 0);
    CHECK(test.width == 0);

    test.initilize(20, 20, 2);

    CHECK(test.grid.size() == 20);
    CHECK(test.grid[0].size() == 20);
    CHECK(test.height == 20);
    CHECK(test.width == 20);

    test.initilize(10, 20, 2);

    CHECK(test.grid.size() == 10);
    CHECK(test.grid[0].size() == 20);
    CHECK(test.height == 20);
    CHECK(test.width == 10);
}

TEST_CASE("getter")
{
    Grid test = Grid();
    test.initilize(10, 20, 2);
    for (int x = 0; x < 10; x++)
        for (int y = 0; y < 20; y++)
        {
            CHECK(test.getCase(Coord(x, y)).getCoord() == Coord(x, y));
            CHECK(test.getCase(x, y).getCoord() == Coord(x, y));
        }
}

DOCTEST_TEST_SUITE_END();