#include <iostream>
using namespace std;        



unsigned long bc(unsigned long n, unsigned long k) {
    if (k > n) {
        return 0;
    }
    
    unsigned long result = 1;
    for (unsigned long i = 1; i <= k; i++) {
        result *= n - (k - i);
        result /= i;
    }
    
    return result;
}

