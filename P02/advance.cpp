#include <iostream>
using namespace std;

bool is_leap_year(int y) {
    bool r;
    if (y % 4 == 0 && y % 100 != 0)
        r = true;
    else if (y % 400 == 0)
        r = true;
    else
        r = false;
    return r;
}
int days_in_month(int m, int y) {
    int d;
    switch (m) {
        case 2:
            d = is_leap_year(y) ? 29 : 28; 
            break;
        case 1: case 3: case 5:
        case 7: case 8: case 10:
        case 12:
            d = 31; 
            break;
        default:
            d = 30; 
            break;
}
    return d;
}

void advance(int delta, int& d, int& m, int& y) {
  while (delta > 0) {
    int days_to_end_of_month = days_in_month(m,y) - d + 1;

    if (delta < days_to_end_of_month) {
      d += delta;
      return;
    }

    // ir para o próximo mês
    delta -= days_to_end_of_month;
    d = 1;
    if (m == 12) {
      m = 1;
      y++;
    } else {
      m++;
    }
  }
}

