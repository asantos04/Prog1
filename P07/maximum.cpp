#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "show_file.h"

using namespace std;

void maximum(const string& input_fname, const string& output_fname) {
    ifstream input_file(input_fname);
    if (!input_file) {
        cerr << "Failed to open input file." << endl;
        return;
    }

    vector<double> values;
    double value;
    while (input_file >> value) {
        values.push_back(value);
    }

    if (values.empty()) {
        cerr << "Input file is empty." << endl;
        return;
    }

    double max_value = *max_element(values.begin(), values.end());

    ofstream output_file(output_fname);
    if (!output_file) {
        cerr << "Failed to open output file." << endl;
        return;
    }

    output_file << fixed << setprecision(3);
    for (double value : values) {
        output_file << value << endl;
    }

    output_file << "count=" << values.size() << "/max=" << max_value << endl;

    input_file.close();
    output_file.close();
}