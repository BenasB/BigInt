#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../src/BigInt.h"

TEST_CASE ("AppendingSingleDigitsAsInt", "[append]")
{
    BigInt bigInt;
    bigInt.appendDigit(1);
    bigInt.appendDigit(2);
    bigInt.appendDigit(3);

    std::string expectedResult = "123";

    REQUIRE(bigInt.getDigitsString() == expectedResult);
}

TEST_CASE ("AppendingMultipleDigitsAsInt", "[append]")
{
    BigInt bigInt;
    bigInt.appendDigits(12);
    bigInt.appendDigits(47);
    bigInt.appendDigits(25);

    std::string expectedResult = "124725";

    REQUIRE(bigInt.getDigitsString() == expectedResult);
}

TEST_CASE ("AppendingSingleDigitsAsChar", "[append]")
{
    BigInt bigInt;
    bigInt.appendDigit('5');
    bigInt.appendDigit('8');
    bigInt.appendDigit('9');

    std::string expectedResult = "589";

    REQUIRE(bigInt.getDigitsString() == expectedResult);
}

TEST_CASE ("AppendingMultipleDigitsAsString", "[append]")
{
    BigInt bigInt;
    bigInt.appendDigits("5780");
    bigInt.appendDigits("022");
    bigInt.appendDigits("56");

    std::string expectedResult = "578002256";

    REQUIRE(bigInt.getDigitsString() == expectedResult);
}

TEST_CASE ("AppendMixed", "[append]")
{
    BigInt bigInt;
    bigInt.appendDigits("872");
    bigInt.appendDigits(123594);
    bigInt.appendDigit('8');
    bigInt.appendDigit(2);
    bigInt.appendDigits("00");

    std::string expectedResult = "8721235948200";

    REQUIRE(bigInt.getDigitsString() == expectedResult);
}

TEST_CASE ("AppendIntOutOfBounds", "[append]")
{
    BigInt bigInt;
    bigInt.appendDigit(15);
    bigInt.appendDigit(17);

    std::string expectedResult = "0";

    REQUIRE(bigInt.getDigitsString() == expectedResult);
}

TEST_CASE ("AppendCharOutOfBounds", "[append]")
{
    BigInt bigInt;
    bigInt.appendDigit((char)5);
    bigInt.appendDigit((char)9);

    std::string expectedResult = "0";

    REQUIRE(bigInt.getDigitsString() == expectedResult);
}