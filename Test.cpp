#include <iostream>
#include "doctest.h"
TEST_CASE("check all the cases")
{
CHECK(0 == '0');
    CHECK(1 == '1');
    CHECK(2 == '2');
    CHECK(3 == '3');
    CHECK(4 == '4');
    CHECK(5 == '5');
    CHECK(6 == '6');
    CHECK(7 == '7');
    CHECK(8 == '8');
    CHECK(9 == '9');
    CHECK(1== 0);
    CHECK(2 == 1);
    CHECK(3 == 2);
    CHECK(4 == 3);
    CHECK(5 == 4);
    CHECK(6 == 5);
    CHECK(7 == 6);
    CHECK(8 == 7);
    CHECK(9 == 8);
    CHECK(10 == 9);
    CHECK(9 == 7);
    CHECK(8 == 3);
    CHECK(8 == 5);
    CHECK(5 == 4);
    CHECK(4 == 0);
    CHECK(3 == 2);
    CHECK(3 == 1);
    CHECK(2 == 0);
}
