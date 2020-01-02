#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../BigInt.h"

TEST_CASE ( "Appending", "[append]" )
{
    BigInt bigInt;
    bigInt.appendDigit(1);
    bigInt.appendDigit(2);
    bigInt.appendDigit(3);

    std::string expectedResult = "123";

    REQUIRE(expectedResult == bigInt.getDigitsString());
}