#include <iostream>
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

unsigned long bell(unsigned long n) {
    unsigned long result = 0;
    if (n==0 or n==1){
      return 1;
    }
    for (unsigned long k = 0; k <= n-1; ++k) {
        result += bc(n-1,k) * bell(k);
    }
    return result;
}




