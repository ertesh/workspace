#include "utils.h"

bool IsLeapYear(int year) {
    bool ret = false;
    if (year % 4 == 0) ret = true;
    if (year % 100 == 0) ret = false;
    if (year % 400 == 0) ret = true;
    return ret;
}
