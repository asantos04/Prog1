#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

double average(const string& fname) {
    ifstream file(fname);
    double sum = 0.0;
    int count = 0;
    while (file.good()) {
        double val;
        file >> val;
        if (file.fail()) {
            file.clear();
            file.ignore(1);
            continue;
        }
        sum += val;
        count++;
    }
    return sum / count;
}
