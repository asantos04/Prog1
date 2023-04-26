#include <algorithm>
using namespace std;

int median(const int a[], int n) {
    // Allocate temporary array
    int* tmp = new int[n];

    // Copy values
    for (int i = 0; i < n; i++) {
      tmp[i] = a[i];
    }
    // Sort values
    sort(tmp, tmp + n);

    // Compute median
    int result = n % 2 != 0  ?
      tmp[n / 2] : (tmp[n / 2 - 1] + tmp[n / 2]) / 2;

    // De-allocate temporary array
    delete [] tmp;

    // Return median
    return result;
}