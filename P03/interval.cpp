#include "interval.h"
#include <iostream>
using namespace std;

bool earlier(time_of_day t1, time_of_day t2){
    if (t1.h==t2.h && t1.m>t2.m)
        return false;    
    if (t1.h>t2.h)
        return false;    
    return true;    
}

interval intersection(interval a, interval b){
    interval i={{00,00}, {00,00}};
    if (earlier(a.start, b.start)){
        i.start=b.start;

        if (earlier(a.end, b.end)) i.end=a.end;
        else i.end=b.end;
        
        if (earlier(a.end, b.start)) i={{00,00}, {00,00}};

    }

    if (earlier(b.start, a.start)){
        i.start=a.start;

        if (earlier(b.end, a.end)) i.end=b.end;
        else i.end=a.end;
        
        if (earlier(b.end, a.start)) i={{00,00}, {00,00}};

    }

    return i;
}
