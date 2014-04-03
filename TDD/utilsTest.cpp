 #include "UnitTest++.h"
 #include "utils.h"

namespace
{

    TEST(OurFirstTest)
    {
        bool result = IsLeapYear(1972);
        CHECK_EQUAL(true, result);

        result = IsLeapYear(1978);
        CHECK_EQUAL(false, result);

        result = IsLeapYear(1900);
        CHECK_EQUAL(false, result);

        result = IsLeapYear(2000);
        CHECK_EQUAL(true, result);
    }

}
