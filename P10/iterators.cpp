#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template <typename Itr> 
string to_string(Itr start, Itr end) {
    ostringstream oss;
    oss << "[ ";
    for (auto it = start; it != end; ++it) {
        oss << *it << ' ';
    }
    oss << "]";
    return oss.str();
}

template <typename Itr, typename T> 
int replace(Itr start, Itr end, const T& a, const T& b) {
    int count = 0;
    for (auto it = start; it != end; ++it) {
        if (*it == a) {
            *it = b;
            count++;
        }
    }
    return count;
}