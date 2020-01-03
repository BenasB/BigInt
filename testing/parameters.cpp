#include "catch.hpp"
#include "../src/BigInt.h"

TEST_CASE ("GetDigitsZero", "[parameters]")
{
    BigInt a;

    int expectedResult = 0;

    REQUIRE(a.getDigitCount() == expectedResult);
}

TEST_CASE ("GetDigitsNonZero", "[parameters]")
{
    BigInt a(68453156);

    int expectedResult = 8;

    REQUIRE(a.getDigitCount() == expectedResult);
}