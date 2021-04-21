#include "models/case.hpp"

#include <array>
#include <doctest/doctest.h>

DOCTEST_TEST_SUITE_BEGIN("case test");

TEST_CASE("constructor")
{
    Case caseForTest = Case(0, 0, 3);
    CHECK_FALSE(caseForTest.containsAnt());
    CHECK(caseForTest.getCoord() == std::array<std::size_t, 2>{0, 0});
}

DOCTEST_TEST_SUITE_END();