#include <iostream>
#include <string>
#include <vector>

std::string longest_prefix(const std::vector<std::string>& v) {
    if (v.empty()) {
        return "";
    }
    int n = v.size();
    std::string prefix = v[0];
    for (int i = 1; i < n; i++) {
        while (v[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) {
                return "";
            }
        }
    }
    return prefix;
}



