#include <iostream>
#include "doctest.h"
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

TEST_CASE("get neigbour")
{
    CHECK(Coord(0, 0).getNeigbour(10, 10) == std::vector<Coord>{Coord(1, 0),
                                                                Coord(0, 1),
                                                                Coord(1, 1)});
    CHECK(Coord(9, 9).getNeigbour(10, 10) == std::vector<Coord>{Coord(8, 8),
                                                                Coord(9, 8),
                                                                Coord(8, 9)});
    CHECK(Coord(5, 0).getNeigbour(10, 10) == std::vector<Coord>{Coord(4, 0),
                                                                Coord(6, 0),
                                                                Coord(4, 1),
                                                                Coord(5, 1),
                                                                Coord(6, 1)});
    CHECK(Coord(0, 5).getNeigbour(10, 10) == std::vector<Coord>{Coord(0, 4),
                                                                Coord(1, 4),
                                                                Coord(1, 5),
                                                                Coord(0, 6),
                                                                Coord(1, 6)});
    CHECK(Coord(5, 9).getNeigbour(10, 10) == std::vector<Coord>{Coord(4, 8),
                                                                Coord(5, 8),
                                                                Coord(6, 8),
                                                                Coord(4, 9),
                                                                Coord(6, 9)});
    CHECK(Coord(9, 5).getNeigbour(10, 10) == std::vector<Coord>{Coord(8, 4),
                                                                Coord(9, 4),
                                                                Coord(8, 5),
                                                                Coord(8, 6),
                                                                Coord(9, 6)});
    CHECK(Coord(5, 5).getNeigbour(10, 10) == std::vector<Coord>{Coord(4, 4),
                                                                Coord(5, 4),
                                                                Coord(6, 4),
                                                                Coord(4, 5),
                                                                Coord(6, 5),
                                                                Coord(4, 6),
                                                                Coord(5, 6),
                                                                Coord(6, 6)});
}

TEST_CASE("is in")
{
    Coord const test1 = Coord(0, 0);
    Coord const test2 = Coord(1, 1);
    Coord const test3 = Coord(1, 3);

    Coord const test4 = Coord(3, 3);
    Coord const test5 = Coord(1, 0);
    Coord const test6 = Coord(6, 4);

    std::vector<Coord> tab = {Coord(0, 0),
                               Coord(1, 1),
                               Coord(1, 3)};
    CHECK(test1.isIn(tab));
    CHECK(test2.isIn(tab));
    CHECK(test3.isIn(tab));

    CHECK_FALSE(test4.isIn(tab));
    CHECK_FALSE(test5.isIn(tab));
    CHECK_FALSE(test6.isIn(tab));
}

TEST_SUITE_END();