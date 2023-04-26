#include <iostream>
using namespace std;
unsigned long pell(unsigned long n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        unsigned long p_prev = 0;
        unsigned long p_curr = 1;
        for (unsigned long i = 2; i <= n; i++) {
            unsigned long p_next = 2 * p_curr + p_prev;
            p_prev = p_curr;
            p_curr = p_next;
        }
        return p_curr;
    }
}