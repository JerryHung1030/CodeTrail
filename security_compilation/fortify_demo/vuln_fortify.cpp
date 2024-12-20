// vuln_fortify.cpp
#include <iostream>
#include <cstring>

int main() {
    char source[] = "This is a very long string that exceeds the buffer size.";
    char buffer[20];
    
    // 使用strcpy，未檢查來源字串長度
    strcpy(buffer, source);
    
    std::cout << "Buffer content: " << buffer << std::endl;
    return 0;
}
