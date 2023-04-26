#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int k;
    int d;
    int sinal=1;
    cin >> k >> d;

    double x = 0.0;
    for (int n = 0; n <= k; n++) {
        x += 4.0 * sinal / (2 * n + 1);
        sinal *= -1;
    }

    cout << fixed << setprecision(d) << x;

    return 0;
}