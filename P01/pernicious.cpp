#include <iostream>
using namespace std;


bool is_prime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
bool is_pernicious(int n) {
    int counter = 0;
    while (n>0) {    
        if (n%2==1) {
            counter++;
        }
        n /= 2;
    }
    if (is_prime(counter)){
        return true;
    }
    return false;
}
int main() {
    int a; int b;
    cin >> a >> b;
    for (int i = a; i<= b ; i++){
        if (is_prime(i) && is_pernicious(i)) {
            cout << i << " ";
        }
    }
    return 0;
}