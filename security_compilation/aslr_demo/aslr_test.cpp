// aslr_test.cpp
#include <iostream>
#include <unistd.h>
#include <sys/mman.h>

int main() {
    std::cout << "Process ID: " << getpid() << std::endl;
    
    // 申請一塊記憶體區域
    void* addr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }
    
    std::cout << "Memory allocated at: " << addr << std::endl;
    
    // 保持程式運行，以便使用其他工具觀察記憶體配置
    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.get();
    
    munmap(addr, 4096);
    return 0;
}
