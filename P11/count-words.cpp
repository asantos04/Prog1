#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

void count_words(const std::string& str, std::map<std::string, size_t>& count) {
    std::istringstream iss(str);
    std::string word;

    while (iss >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        count[word]++;
    }
}

void show_map(const std::map<std::string, size_t>& count) {
    std::cout << "[ ";
    for (const auto& e : count) {
        std::cout << e.first << ":" << e.second << ' ';
    }
    std::cout << "]\n";
}

