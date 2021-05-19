#include "models/colony.hpp"
#include "doctest.h"

DOCTEST_TEST_SUITE_BEGIN("colony test");

TEST_CASE("constructor")
{
    Colony test = Colony(Coord(0, 0), 0);
    CHECK(test.sugar == 10);
    CHECK(test.base == Coord(0, 0));
    CHECK(test.team == 0);
    CHECK(test.nest == std::vector<Coord>{Coord(0, 0)});
}

TEST_CASE("Modifier")
{
    Coord base = Coord(0, 0);
    Colony test = Colony(base, 0);
    SUBCASE("add nest")
    {
        Coord test1 = Coord(0, 1);
        Coord test2 = Coord(0, 2);
        Coord test3 = Coord(0, 3);

        test.addNest(test1);
        test.addNest(test2);
        test.addNest(test3);
        CHECK(test.nest == std::vector<Coord>{base,
                                              test1,
                                              test2,
                                              test3});
        test.removeNest(test2);
        CHECK(test.nest == std::vector<Coord>{base,
                                              test1,
                                              test3});
        test.removeNest(test1);
        CHECK(test.nest == std::vector<Coord>{base,
                                              test3});
        test.removeNest(base);
        CHECK(test.nest == std::vector<Coord>{test3});

        test.removeNest(test3);
        CHECK(test.nest == std::vector<Coord>{});
    }

    SUBCASE("ant")
    {
        test.ants.push_back(Ant(0, Coord(0, 0), 0, Coord(0, 0)));
        test.ants.push_back(Ant(0, Coord(0, 0), 0, Coord(0, 0)));
        test.ants.push_back(Ant(0, Coord(0, 0), 0, Coord(0, 0)));
        test.ants.push_back(Ant(0, Coord(0, 0), 0, Coord(0, 0)));
        test.ants.push_back(Ant(0, Coord(0, 0), 0, Coord(0, 0)));
        for (int i = 0; i < test.getNbAnt(); i++)
        {
            CHECK(test.getNbAnt() == 5);
            CHECK(test.getNbAntDead() == i);
            CHECK(test.getNbAntInLife() == 5 - i);
            test.ants[i].kill();
        }
        CHECK(test.getNbAnt() == 5);
        CHECK(test.getNbAntDead() == 5);
        CHECK(test.getNbAntInLife() == 0);
    }
}

DOCTEST_TEST_SUITE_END();