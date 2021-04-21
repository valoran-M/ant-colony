#include "models/case.hpp"

#include <array>
#include <doctest/doctest.h>
#include <stdexcept>

DOCTEST_TEST_SUITE_BEGIN("case test");

TEST_CASE("constructor")
{
    Case caseForTest = Case(0, 0, 3);
    CHECK_FALSE(caseForTest.containsAnt());
    CHECK(caseForTest.getCoord() == std::array<std::size_t, 2>{0, 0});
    CHECK(caseForTest.getNest() == -1);
    CHECK(caseForTest.getAnt() == -1);
    CHECK(caseForTest.getSugar() == -1);
    CHECK(caseForTest.getSugarPhero() == 0);
    for (size_t i = 0; i < 3; i++)
        CHECK(caseForTest.getNestPhero(i) == 0);
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
        caseForTest.putAnt(1);
        CHECK(caseForTest.getAnt() == 1);
        CHECK_THROWS_AS(caseForTest.putAnt(5),
                        std::invalid_argument);
    }
    SUBCASE("Sugar")
    {
        caseForTest.putSugar(4);
        CHECK(caseForTest.getSugar() == 4);
        CHECK_THROWS_AS(caseForTest.putSugar(5),
                        std::invalid_argument);
        caseForTest.removeSugar();
        CHECK(caseForTest.getSugar() == -1);
    }
    SUBCASE("Neats")
    {
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
        caseForTest.putSugarPheromone(100);
        CHECK(caseForTest.getSugarPhero() == 100);

        // decreases
        caseForTest.decreasesSugarPheromone(50);
        CHECK(caseForTest.getSugarPhero() == 50);
        caseForTest.decreasesSugarPheromone(25);
        CHECK(caseForTest.getSugarPhero() == 25);
        caseForTest.decreasesSugarPheromone(50);
        CHECK(caseForTest.getSugarPhero() == 0);
    }
}

TEST_CASE("Predicate")
{
    Case caseForTest = Case(0, 0, 3);
    SUBCASE("ant")
    {
        CHECK_FALSE(caseForTest.containsAnt());
        caseForTest.putAnt(4);
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
}

DOCTEST_TEST_SUITE_END();