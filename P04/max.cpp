#include <iostream>
using namespace std;

int max(const int a[], int n){
  int m = a[0];
  for (int i = 0; i < n; i++) {
    int v = a[i];
    if (v>m){
      m = v;
    }
  }
  return m;
}
