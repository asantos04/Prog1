#include <iostream>
using namespace std;
int max(int a, int b, int c){
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}
int min(int a, int b, int c){
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;

}
int adigits(int a, int b, int c) {
    int r1 = max(a,b,c);
    int r3 = min(a,b,c);
    int r2 = a + b + c - r1 - r3;
    int num = r1*100 + r2*10 + r3;
    return num;

}
