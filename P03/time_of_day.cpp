#include <iostream>
#include "time_of_day.h"
using namespace std;

time_of_day tick(time_of_day t) {
    if (t.m < 59) {
        t.m++;
    } else {
        t.m = 0;
        if (t.h < 23) {
            t.h++;
        } else {
            t.h = 0;
        }
    }
    return t;
}
