#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "show_file.h"

void calc_medians(const std::string &input_fname, const std::string &output_fname)
{
    std::ifstream input_file(input_fname);
    std::ofstream output_file(output_fname);

    std::string line;
    while (std::getline(input_file, line))
    {
        if (line.empty() || line[0] == '#')
        {
            continue; // ignore empty or comment lines
        }
        std::istringstream iss(line);
        std::string id;
        std::vector<double> values;
        iss >> id;
        double val;
        while (iss >> val)
        {
            values.push_back(val);
        }
        std::sort(values.begin(), values.end());
        double median;
        int n = values.size();
        if (n % 2 == 1)
        {
            median = values[n / 2];
        }
        else
        {
            median = 0.5 * (values[n / 2 - 1] + values[n / 2]);
        }
        output_file << id << " " << std::fixed << std::setprecision(1) << median << std::endl;
    }
    input_file.close();
    output_file.close();
}