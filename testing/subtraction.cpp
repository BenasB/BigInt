#include "catch.hpp"
#include "../src/BigInt.h"

TEST_CASE ("SubtractZeroFromZero", "[subtraction]")
{
    BigInt a;
    BigInt b;
    BigInt c = a - b;

    std::string expectedResult = "0";

    REQUIRE(c.getDigitsString() == expectedResult);
}

TEST_CASE ("SubtractZero", "[subtraction]")
{
    BigInt a(48465);
    BigInt b;
    BigInt c = a - b;

    std::string expectedResult = "48465";

    REQUIRE(c.getDigitsString() == expectedResult);
}

TEST_CASE ("SubtractWithSameDigitCount", "[subtraction]")
{
    BigInt a(48465);
    BigInt b(15486);
    BigInt c = a - b;

    std::string expectedResult = "32979";

    REQUIRE(c.getDigitsString() == expectedResult);
}

TEST_CASE ("SubtractWithSameDigitCountBig", "[subtraction]")
{
    BigInt a("4894351845318945618456153189456156564968");
    BigInt b("3151548456415465418945148451515489456122");
    BigInt c = a - b;

    std::string expectedResult = "1742803388903480199511004737940667108846";

    REQUIRE(c.getDigitsString() == expectedResult);
}

TEST_CASE ("SubtractWithDifferentDigitCount", "[subtraction]")
{
    BigInt a(215615);
    BigInt b(3656);
    BigInt c = a - b;

    std::string expectedResult = "211959";

    REQUIRE(c.getDigitsString() == expectedResult);
}

TEST_CASE ("SubtractWithDifferentDigitCountBig", "[subtraction]")
{
    BigInt a("798456489531561423");
    BigInt b("45645648452151");
    BigInt c = a - b;

    std::string expectedResult = "798410843883109272";

    REQUIRE(c.getDigitsString() == expectedResult);
}