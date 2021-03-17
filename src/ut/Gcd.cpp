#include "catch/catch.hpp"

int gcd(int a, int b)
{
    while(a != b)
    {
        if(a > b)
            a -= b;
        else
            b -= a;
    }

    return a;
}

TEST_CASE("Factorials are computed", "[factorial]")
{
    REQUIRE(gcd(10, 5) == 5);
    REQUIRE(gcd(100, 18) == 2);
    REQUIRE(gcd(10, 10) == 10);
    REQUIRE(gcd(100, 1) == 1);
    // REQUIRE(gcd(0, 10) == 10);
}
