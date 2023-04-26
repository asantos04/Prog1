#include <iostream>
#include "interval.h"
using namespace std;

bool earlierthan(time_of_day a, time_of_day b, int inclusive) {
  if (inclusive == 1){
    if (a.h == b.h and a.m < b.m) return true;
    }
    else {
      if (a.h == b.h and a.m <= b.m) return true;}
    if (a.h < b.h) return true;
    return false;
}
int search_intervals(time_of_day t, const interval a[], int n, interval& u){
  int flag = 0; time_of_day earliest = t, latest = t;
  for (int i=0; i<n;i++) {
    interval x = a[i];
    if (earlierthan(t,x.start,1))
      continue;
    else if (earlierthan(x.end, t, 0))
      continue;
    else {
      if (flag == 0) {
        earliest = x.start;
        latest = x.end;
        flag = 1;       continue;
      }
      if (earlierthan(x.start, earliest, 0)) earliest = x.start;
      if (earlierthan(latest,x.end,0)) latest = x.end;
    }
  }
  u = {earliest, latest};
  if (flag == 0)
    return 0;
  return (latest.h - earliest.h) * 60 + latest.m - earliest.m;
}
  