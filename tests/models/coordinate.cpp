#include <doctest/doctest.h>

#include "models/coordinate.hpp"

TEST_SUITE_BEGIN("");

TEST_CASE("Constructor and [] operator")
{
    Coord test1 = Coord(1, 2);
    CHECK(test1[0] == 1);
    CHECK(test1[1] == 2);
    Coord test2 = Coord(5, 1);
    CHECK(test2[0] == 5);
    CHECK(test2[1] == 1);
    Coord test3 = Coord(8, 0);
    CHECK(test3[0] == 8);
    CHECK(test3[1] == 0);
}

TEST_CASE("operator bool")
{

    Coord test1 = Coord(1, 2);
    Coord test2 = Coord(1, 2);
    Coord test3 = Coord(5, 7);
    Coord test4 = Coord(1, 4);
    Coord test5 = Coord(3, 2);

    SUBCASE("==")
    {
        CHECK(test1 == test2);
        CHECK_FALSE(test1 == test3);
        CHECK_FALSE(test1 == test3);
        CHECK_FALSE(test1 == test4);
        CHECK_FALSE(test1 == test5);
    }
    SUBCASE("!=")
    {
        CHECK_FALSE(test1 != test2);
        CHECK(test1 != test3);
        CHECK(test1 != test3);
        CHECK(test1 != test4);
        CHECK(test1 != test5);
    }
}

TEST_SUITE_END();