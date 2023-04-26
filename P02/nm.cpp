#include <iostream>
using namespace std;
unsigned long next_mersenne(unsigned long n) {
    if (n==0){
      return 0;
    }
    unsigned long m = 1;
    while (m < n) {
        m = (m << 1) + 1;
    }
    return m;
}
