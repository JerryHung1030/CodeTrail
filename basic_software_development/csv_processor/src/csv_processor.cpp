// csv_processor.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

struct Statistics {
    double mean;
    double variance;
};

Statistics calculate_statistics(const std::vector<double> &data) {
    Statistics stats;
    double sum = 0.0;
    for(auto num : data) sum += num;
    stats.mean = sum / data.size();

    double var_sum = 0.0;
    for(auto num : data) var_sum += (num - stats.mean) * (num - stats.mean);
    stats.variance = var_sum / data.size();

    return stats;
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cerr << "Usage: ./csv_processor <csv_file> <column_index>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if(!file.is_open()) {
        std::cerr << "Cannot open file: " << argv[1] << "\n";
        return 1;
    }

    int column = std::stoi(argv[2]);
    std::string line, cell;
    std::vector<double> data;

    while(std::getline(file, line)) {
        std::stringstream ss(line);
        int current = 0;
        while(std::getline(ss, cell, ',')) {
            if(current == column) {
                try {
                    data.push_back(std::stod(cell));
                } catch(...) {
                    // 忽略非數值單元格
                }
                break;
            }
            current++;
        }
    }

    if(data.empty()) {
        std::cerr << "No data found in column " << column << "\n";
        return 1;
    }

    Statistics stats = calculate_statistics(data);
    std::cout << "Mean: " << stats.mean << "\n";
    std::cout << "Variance: " << stats.variance << "\n";

    return 0;
}
