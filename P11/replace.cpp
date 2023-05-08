#include <iostream>
#include <map>
#include <string>

void replace(const std::map<char, char>& r, std::string& s) {
    for (size_t i = 0; i < s.length(); ++i) {
        auto it = r.find(s[i]);
        if (it != r.end()) {
            s[i] = it->second;
        }
    }
}

