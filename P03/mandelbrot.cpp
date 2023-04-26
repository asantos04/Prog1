#include <iostream>
#include "complex.h"
#include <cmath>
using namespace std;

void add(const complex& a, const complex& b, complex& r){
    r.x=a.x+b.x;
    r.y=a.y+b.y;
}

void mul(const complex& a, const complex& b, complex& r){
    r.x=a.x*b.x-a.y*b.y;
    r.y=a.x*b.y+a.y*b.x;
}

void mandelbrot(const complex& c, unsigned int n, complex& z_n){
    z_n = {0,0};
    complex m = {0,0};
    complex a = {0,0};

    for (unsigned int i = 0; i < n; i++) {
        mul(z_n,z_n, m);
        add(m, c, a);
        z_n=a;
    }

}