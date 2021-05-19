#include "models/data.hpp"
#include "doctest.h"

#include <math.h>

DOCTEST_TEST_SUITE_BEGIN("data");

TEST_CASE("constructor")
{
    unsigned int colony = 1, sugar = 10;
    int cellDim = 10;
    Coord gridDim = Coord(20, 20);

    Data test1 = Data(colony, sugar, cellDim, gridDim);
    CHECK(test1.state == Data::State::menu);
    CHECK(test1.lap == 0);
    CHECK(test1.speed == 1);
    CHECK(test1.numberOfColony == colony);
    CHECK(test1.sugar == sugar);
    CHECK(test1.caseSize == cellDim);
    CHECK(test1.width == gridDim[0]);
    CHECK(test1.height == gridDim[1]);
    CHECK(test1.sugarPhero == std::vector<std::vector<Coord>>{});
    float decrease = 1 / std::sqrt(
                             float(test1.width * test1.width + test1.height * test1.height));
    decrease /= 2;
    CHECK(test1.decrease == decrease);

    colony = 4, sugar = 2;
    cellDim = 30;
    gridDim = Coord(30, 30);

    Data test2 = Data(colony, sugar, cellDim, gridDim);
    CHECK(test2.state == Data::State::menu);
    CHECK(test2.lap == 0);
    CHECK(test2.speed == 1);
    CHECK(test2.numberOfColony == colony);
    CHECK(test2.sugar == sugar);
    CHECK(test2.caseSize == cellDim);
    CHECK(test2.width == gridDim[0]);
    CHECK(test2.height == gridDim[1]);
    CHECK(test2.sugarPhero == std::vector<std::vector<Coord>>{});

    decrease = 1 / std::sqrt(
                       float(test2.width * test2.width + test2.height * test2.height));
    decrease /= 2;
    CHECK(test2.decrease == decrease);
}

TEST_CASE("fucntion")
{
    unsigned int colony = 1, sugar = 10;
    int cellDim = 10;
    Coord gridDim = Coord(20, 20);

    Data test1 = Data(colony, sugar, cellDim, gridDim);

    for (int i = 0; i < 20; i++)
    {
        CHECK(test1.lap == i);
        test1.addLap();
    }
}

DOCTEST_TEST_SUITE_END();