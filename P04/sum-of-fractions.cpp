#include "fraction.h"

int gcd(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

fraction sum(const fraction fa[], int n) {
  fraction s { 0, 1 };
  for (int i = 0; i < n; i++) {
    int n = s.num * fa[i].den + fa[i].num * s.den,
        d = s.den * fa[i].den,
        g = gcd(n, d);
    s.num = n / g;
    s.den = d / g; 
  }
  if (s.den < 0) {
    s.num = - s.num; 
    s.den = - s.den;
  }
  return s;
}
