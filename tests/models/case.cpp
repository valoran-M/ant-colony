#include "models/case.hpp"
#include "models/coordinate.hpp"
#include "doctest.h"

#include <array>
#include <stdexcept>

DOCTEST_TEST_SUITE_BEGIN("case test");

TEST_CASE("constructor")
{
    Case caseForTest = Case(0, 0, 3);
    CHECK_FALSE(caseForTest.containsAnt());
    CHECK(caseForTest.getCoord() == Coord(0, 0));
    CHECK(caseForTest.getNest() == -1);
    CHECK(caseForTest.getAnt() == -1);
    CHECK(caseForTest.getSugar() == -1);
    for (size_t i = 0; i < 3; i++)
    {
        CHECK(caseForTest.getNestPhero(i) == 0);
        CHECK(caseForTest.getSugarPhero(i) == 0);
    }
    CHECK_FALSE(caseForTest.containsAnt());
    CHECK_FALSE(caseForTest.containsNest());
    CHECK_FALSE(caseForTest.containsSugar());
    CHECK(caseForTest.isEmpty());
}

TEST_CASE("modifier")
{
    Case caseForTest = Case(0, 0, 3);
    SUBCASE("Ant")
    {
        CHECK(caseForTest.getAnt() == -1);
        caseForTest.putAnt(1, 1);
        CHECK(caseForTest.getAnt() == 1);
        CHECK_THROWS_AS(caseForTest.putAnt(5, 1),
                        std::invalid_argument);
        caseForTest.removeAnt();
        CHECK(caseForTest.getAnt() == -1);
    }
    caseForTest = Case(0, 0, 3);
    SUBCASE("Sugar")
    {
        CHECK(caseForTest.getSugar() == -1);
        caseForTest.putSugar(4);
        CHECK(caseForTest.getSugar() == 4);
        CHECK_THROWS_AS(caseForTest.putSugar(5),
                        std::invalid_argument);
        caseForTest.removeSugar();
        CHECK(caseForTest.getSugar() == -1);
    }
    caseForTest = Case(0, 0, 3);
    SUBCASE("Neats")
    {
        CHECK(caseForTest.getNest() == -1);
        caseForTest.putNeast(4);
        CHECK(caseForTest.getNest() == 4);
        CHECK_THROWS_AS(caseForTest.putNeast(5),
                        std::invalid_argument);
    }
    SUBCASE("Neast pheromone")
    {
        caseForTest.putNestPheromone(0, 4);
        CHECK(caseForTest.getNestPhero(0) == 4);
        caseForTest.putNestPheromone(1, 3);
        CHECK(caseForTest.getNestPhero(1) == 3);
        caseForTest.putNestPheromone(2, 0);
        CHECK(caseForTest.getNestPhero(2) == 0);
        CHECK_THROWS_AS(caseForTest.putNestPheromone(5, 0),
                        std::invalid_argument);
    }
    SUBCASE("Sugar pheromone")
    {
        // put
        caseForTest.putSugarPheromone(0, 100);
        CHECK(caseForTest.getSugarPhero(0) == 100);

        // decreases
        caseForTest.decreasesSugarPheromone(0, 50);
        CHECK(caseForTest.getSugarPhero(0) == 50);
        caseForTest.decreasesSugarPheromone(0, 25);
        CHECK(caseForTest.getSugarPhero(0) == 25);
        caseForTest.decreasesSugarPheromone(0, 50);
        CHECK(caseForTest.getSugarPhero(0) == 0);
    }
}

TEST_CASE("Predicate")
{
    Case caseForTest = Case(0, 0, 3);
    SUBCASE("ant")
    {
        CHECK_FALSE(caseForTest.containsAnt());
        caseForTest.putAnt(4, 1);
        CHECK(caseForTest.containsAnt());
        caseForTest.removeAnt();
        CHECK_FALSE(caseForTest.containsAnt());
    }
    SUBCASE("nest")
    {
        CHECK_FALSE(caseForTest.containsNest());
        caseForTest.putNeast(4);
        CHECK(caseForTest.containsNest());
    }
    SUBCASE("sugar")
    {
        CHECK_FALSE(caseForTest.containsSugar());
        caseForTest.putSugar(5);
        CHECK(caseForTest.containsSugar());
        caseForTest.removeSugar();
        CHECK_FALSE(caseForTest.containsSugar());
    }

    SUBCASE("empty")
    {
        Case caseForEmptyTest = Case(0, 0, 3);
        CHECK(caseForEmptyTest.isEmpty());
        caseForEmptyTest.putAnt(1, 1);
        CHECK_FALSE(caseForEmptyTest.isEmpty());
        caseForEmptyTest.removeAnt();
        caseForEmptyTest.putSugar(1);
        CHECK_FALSE(caseForEmptyTest.isEmpty());
        caseForEmptyTest.removeSugar();
        caseForEmptyTest.putNeast(7);
        CHECK_FALSE(caseForEmptyTest.isEmpty());
    }
}

DOCTEST_TEST_SUITE_END();