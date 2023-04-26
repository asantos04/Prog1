#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int x, y, x_prev, y_prev, distance = 0;
    cin >> x >> y;
    x_prev = x;
    y_prev = y;

    for (int i = 2; i <= n; i++) {
        cin >> x >> y;
        distance += abs(x - x_prev) + abs(y - y_prev);
        x_prev = x;
        y_prev = y;
    }

    cout << distance ;
    return 0;
}





