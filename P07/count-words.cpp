#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int count(const string& fname, const string& word) {
    ifstream in(fname);
    string palavra = word;
    int count = 0;
    for (char& c : palavra) c = toupper(c); 
    for (string s; in >> s;) {
        for (char& d : s) d = toupper(d); 
        if (s == palavra) {
            count++;
        }
        }
    return count;
}

int main() {
    cout << count("p1_test_a.txt", "THE") << '\n';
    cout << count("p1_test_a.txt", "0") << '\n';
    return 0;
}