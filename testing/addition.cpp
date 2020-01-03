#include "catch.hpp"
#include "../src/BigInt.h"

TEST_CASE ("AddTwoZeros", "[addition]")
{
    BigInt a;
    BigInt b;
    BigInt c = a + b;

    std::string expectedResult = "0";

    REQUIRE(c.getDigitsString() == expectedResult);
}

TEST_CASE ("AddWithSameDigitCount", "[addition]")
{
    BigInt a(684);
    BigInt b(843);
    BigInt c = a + b;

    std::string expectedResult = "1527";

    REQUIRE(c.getDigitsString() == expectedResult);
}

TEST_CASE ("AddWithSameDigitCountBig", "[addition]")
{
    BigInt a("984548945615648945613564984765143213");
    BigInt b("265489456184651235165848945645649846");
    BigInt c = a + b;

    std::string expectedResult = "1250038401800300180779413930410793059";

    REQUIRE(c.getDigitsString() == expectedResult);
}

TEST_CASE ("AddWithDifferentDigitCount", "[addition]")
{
    BigInt a(73654);
    BigInt b(954);
    BigInt c;
    
    c = a + b;

    std::string expectedResult = "74608";

    REQUIRE(c.getDigitsString() == expectedResult);
}

TEST_CASE ("AddWithDifferentDigitCountBig", "[addition]")
{
    BigInt a("123468481423519848641231689456156198456123");
    BigInt b("435498435158643548646841532489");
    BigInt c = a + b;

    std::string expectedResult = "123468481423955347076390333004803039988612";

    REQUIRE(c.getDigitsString() == expectedResult);
}

TEST_CASE ("AddWithAdditionAssignmentOperator", "[addition]")
{
    BigInt a("8945684894519846512489423");
    BigInt b("146548941231986");

    a += b;

    std::string expectedResult = "8945684894666395453721409";

    REQUIRE(a.getDigitsString() == expectedResult);
}

TEST_CASE ("AddWithIncrementOperator", "[addition]")
{
    BigInt a;
    
    for (int i = 0; i < 100; i++)
    {
        a++;
    }

    std::string expectedResult = "100";

    REQUIRE(a.getDigitsString() == expectedResult);
}

TEST_CASE ("AddMultipleNumbers", "[addition]")
{
    BigInt a("564984564189456156");
    BigInt b("489456456");
    BigInt c("54");
    BigInt d("19848945641984651658494554");

    BigInt e = a + b + c + d;

    std::string expectedResult = "19848946206969216337407220";

    REQUIRE(e.getDigitsString() == expectedResult);
}