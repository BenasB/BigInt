#include "catch.hpp"
#include "../src/BigInt.h"

TEST_CASE ("ConstructFromNothing", "[construct]")
{
    BigInt bigInt;

    std::string expectedResult = "0";

    REQUIRE(bigInt.getDigitsString() == expectedResult);
}

TEST_CASE ("ConstructFromInt", "[construct]")
{
    BigInt bigInt(54569871);

    std::string expectedResult = "54569871";

    REQUIRE(bigInt.getDigitsString() == expectedResult);
}

TEST_CASE ("ConstructFromString", "[construct]")
{
    BigInt bigInt("1287569874564564798423519854565498465");

    std::string expectedResult = "1287569874564564798423519854565498465";

    REQUIRE(bigInt.getDigitsString() == expectedResult);
}