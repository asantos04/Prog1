#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int letter_count = 0;
    int digit_count = 0;
    int other_count = 0;

    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;

        if (c >= '0' && c <= '9') {
            digit_count++;
        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            letter_count++;
        } else {
            other_count++;
        }
    }

    cout << letter_count << " " << digit_count << " " << other_count;

    return 0;
}