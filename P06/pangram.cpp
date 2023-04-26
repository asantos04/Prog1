#include <iostream>
#include <string>       
#include <algorithm>    
using namespace std;

bool pangram(const string& s, string& m) {
    bool present[26] = { false };

    
    for (char c : s) {
        
        if (c >= 'A' && c <= 'Z') {
            c += ('a' - 'A');
        }

        
        if (c >= 'a' && c <= 'z') {
            present[c - 'a'] = true;
        }
    }

    
    bool is_pangram = true;
    for (int i = 0; i < 26; i++) {
        if (!present[i]) {
            is_pangram = false;
            m += (char)('a' + i); 
        }
    }

   
    sort(m.begin(), m.end());

    return is_pangram;
}