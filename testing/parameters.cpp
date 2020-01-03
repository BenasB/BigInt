#include "catch.hpp"
#include "../src/BigInt.h"

TEST_CASE ("GetDigitsZero", "[parameters]")
{
    BigInt a;

    int expectedResult = 1;

    REQUIRE(a.getDigitCount() == expectedResult);
}

TEST_CASE ("GetDigitsNonZero", "[parameters]")
{
    BigInt a(68453156);

    int expectedResult = 8;

    REQUIRE(a.getDigitCount() == expectedResult);
}

TEST_CASE ("GetCharArrayZero", "[parameters]")
{
    BigInt a;

    char expectedResult = '0';

    REQUIRE(a.getDigitCount() == 1);

    char* digits = a.getDigitsArray();
    for (int i = 0; i < a.getDigitCount(); i++)
    {
        REQUIRE(digits[i] == expectedResult);
    }
}

TEST_CASE ("GetCharArrayNonZero", "[parameters]")
{
    BigInt a("5486279853");

    char* expectedResult = new char[10] {'5', '4', '8', '6', '2', '7', '9', '8', '5', '3'};

    REQUIRE(a.getDigitCount() == 10);

    char* digits = a.getDigitsArray();
    for (int i = 0; i < a.getDigitCount(); i++)
    {
        REQUIRE(digits[i] == expectedResult[i]);
    }
}