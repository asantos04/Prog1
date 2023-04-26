#include <iostream>
#include <string>
#include <vector>
#include "print_string.h"

void split(const std::string& s, std::vector<std::string>& v) {
    std::string::size_type pos = 0, last_pos = 0;
    while ((pos = s.find(' ', last_pos)) != std::string::npos) {
        if (pos > last_pos) {
            v.push_back(s.substr(last_pos, pos - last_pos));
        }
        last_pos = pos + 1;
    }
    if (last_pos < s.length()) {
        v.push_back(s.substr(last_pos));
    }
}