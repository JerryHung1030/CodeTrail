// vuln_buffer.cpp
#include <iostream>
#include <cstring>

int main() {
    char buffer[10];
    std::cout << "Enter a string: ";
    std::cin >> buffer; // 未限制輸入長度，可能導致緩衝區溢位
    std::cout << "You entered: " << buffer << std::endl;
    return 0;
}
