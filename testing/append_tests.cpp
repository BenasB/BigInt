#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../BigInt.h"

TEST_CASE ( "AppendingSingleDigitAsInt", "[append]" )
{
    BigInt bigInt;
    bigInt.appendDigit(1);
    bigInt.appendDigit(2);
    bigInt.appendDigit(3);

    std::string expectedResult = "123";

    REQUIRE(expectedResult == bigInt.getDigitsString());
}

TEST_CASE ( "AppendingMultipleDigitsAsInt", "[append]" )
{
    BigInt bigInt;
    bigInt.appendDigits(12);
    bigInt.appendDigits(47);
    bigInt.appendDigits(25);

    std::string expectedResult = "124725";

    REQUIRE(expectedResult == bigInt.getDigitsString());
}