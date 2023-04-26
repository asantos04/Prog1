#include <iostream>
#include <fstream>
#include <string>
#include "print.h"

using namespace std;

void normalise(const string& input_fname, const string& output_fname) {

    ifstream input_file(input_fname);
    if (!input_file.is_open()) {
        cerr << "Error: could not open input file '" << input_fname << "'" << endl;
        return;
    }

    
    ofstream output_file(output_fname);
    if (!output_file.is_open()) {
        cerr << "Error: could not open output file '" << output_fname << "'" << endl;
        return;
    }

    
    string line;
    while (getline(input_file, line)) {
    
        size_t first_non_space = line.find_first_not_of(" ");
        if (first_non_space == string::npos) {
       
            continue;
        }
        size_t last_non_space = line.find_last_not_of(" ");
        line = line.substr(first_non_space, last_non_space - first_non_space + 1);

      
        for (char& c : line) {
            c = toupper(c);
        }

    
        output_file << line << endl;
    }


    input_file.close();
    output_file.close();
}