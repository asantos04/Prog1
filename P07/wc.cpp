#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "wc.h" 

using namespace std;

wcresult wc(const string& filename) {
    ifstream ifs(filename); 
    string line;
    unsigned int lines = 0;
    unsigned int words = 0;
    unsigned int bytes = 0;

    while (getline(ifs, line)) { 
        lines++;
        bytes += line.length() + 1; 
        istringstream iss(line); 
        string word;
        while (iss >> word) { 
            words++;
        }
    }

    wcresult result = {lines, words, bytes};
    return result;
}