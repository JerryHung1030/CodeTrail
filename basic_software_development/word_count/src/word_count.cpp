#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

int main(int argc, char* argv[]) {
    // 檢查是否提供了檔案名稱作為參數
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file_name>" << std::endl;
        return 1;
    }

    // 打開指定的檔案
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return 1;
    }

    std::map<std::string, int> word_map;
    std::string line, word;

    // 逐行讀取檔案內容
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        while (ss >> word) {
            ++word_map[word];
        }
    }

    // 關閉檔案
    file.close();

    // 輸出每個單詞的出現次數
    for (const auto &pair : word_map) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
