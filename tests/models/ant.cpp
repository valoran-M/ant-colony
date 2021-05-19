#include "models/ant.hpp"
#include "models/coordinate.hpp"

#include "doctest.h"
#include <stdexcept>

DOCTEST_TEST_SUITE_BEGIN("ant test");

TEST_CASE("constructor")
{
    Ant testFourmis = Ant(0, Coord(0, 0), 1, Coord(0, 0));
    CHECK(testFourmis.getCoord() == Coord(0, 0));
    CHECK(testFourmis.getLifePoint() == 10);
    CHECK(testFourmis.getNumber() == 0);
    CHECK(testFourmis.getEnergy() == 5);
    CHECK(testFourmis.getSugar() == 0);
}

TEST_CASE("modifier")
{
    Ant testFourmis = Ant(0, Coord(0, 0), 1, Coord(0, 0));
    SUBCASE("takeSugar")
    {
        testFourmis.takeSugar();
        CHECK(testFourmis.getSugar() == 1);
        CHECK(testFourmis.getEnergy() == 4);
        testFourmis.takeSugar();
        testFourmis.takeSugar();
        CHECK(testFourmis.getSugar() == 3);
        CHECK(testFourmis.getEnergy() == 2);
        CHECK_THROWS_AS(testFourmis.takeSugar(),
                        std::invalid_argument);
    }

    SUBCASE("dropSugar")
    {
        CHECK(testFourmis.dropSugar() == 0);
        testFourmis.dropSugar();
        CHECK(testFourmis.getSugar() == 0);
        CHECK(testFourmis.getEnergy() == 5);
        for (int i = 0; i < 3; i++)
        {
            testFourmis.takeSugar();
        }
        CHECK(testFourmis.dropSugar() == 3);
    }

    SUBCASE("move")
    {
        testFourmis.move(1, 1);
        CHECK(testFourmis.getCoord() == Coord(1, 1));
        testFourmis.move(1, 0);
        CHECK(testFourmis.getCoord() == Coord(2, 1));
        testFourmis.move(0, 1);
        CHECK(testFourmis.getCoord() == Coord(2, 2));
        testFourmis.move(-1, -1);
        CHECK(testFourmis.getCoord() == Coord(1, 1));
    }

    SUBCASE("Rotation")
    {
        CHECK(testFourmis.getRotation() == Coord(0, 0));
        testFourmis.getRotation() = Coord(1, 1);
        CHECK(testFourmis.getRotation() == Coord(1, 1));
        testFourmis.getRotation() = Coord(0, 1);
        CHECK(testFourmis.getRotation() == Coord(0, 1));
        testFourmis.getRotation() = Coord(-1, -1);
        CHECK(testFourmis.getRotation() == Coord(-1, -1));
    }

    SUBCASE("go to")
    {
        Coord test1 = Coord(1, 1);
        Coord test2 = Coord(10, 3);
        CHECK(testFourmis.getCoord() == Coord(0, 0));
        testFourmis.go_to(test1);
        CHECK(testFourmis.getCoord() == test1);
        testFourmis.go_to(test2);
        CHECK(testFourmis.getCoord() == test2);
    }
}

TEST_CASE("Predicat")
{
    Ant testFourmis = Ant(0, Coord(0, 0), 1, Coord(0, 0));
    SUBCASE("inLife")
    {
        CHECK(testFourmis.inLife());
        testFourmis.kill();
        CHECK_FALSE(testFourmis.inLife());
    }

    SUBCASE("haveSugar")
    {
        CHECK_FALSE(testFourmis.haveSugar());
        testFourmis.takeSugar();
        CHECK(testFourmis.haveSugar());
        testFourmis.takeSugar();
        CHECK(testFourmis.haveSugar());
    }

    SUBCASE("research")
    {
        CHECK(testFourmis.research());
        testFourmis.takeSugar();
        CHECK_FALSE(testFourmis.research());
        testFourmis.dropSugar();
        CHECK(testFourmis.research());
    }

    SUBCASE("backHome")
    {
        CHECK_FALSE(testFourmis.backHome());
        testFourmis.takeSugar();
        CHECK(testFourmis.backHome());
        testFourmis.dropSugar();
        CHECK_FALSE(testFourmis.backHome());
    }
}

DOCTEST_TEST_SUITE_END();