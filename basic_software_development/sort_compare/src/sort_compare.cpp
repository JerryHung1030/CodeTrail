// sort_compare.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

// bubble_sort
void bubble_sort(std::vector<int> &arr) {
    int n = arr.size();
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

// quick_sort（使用C++標準庫的sort）
void quick_sort(std::vector<int> &arr) {
    std::sort(arr.begin(), arr.end());
}

int main() {
    const int SIZE = 10000;
    std::vector<int> data(SIZE);
    std::mt19937 gen(42); // 固定種子以確保可重現性
    std::uniform_int_distribution<> dis(1, 100000);
    for(auto &num : data) num = dis(gen);

    // 冒泡排序測試
    std::vector<int> data_bubble = data;
    auto start = std::chrono::high_resolution_clock::now();
    bubble_sort(data_bubble);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration_bubble = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    // 快速排序測試
    std::vector<int> data_quick = data;
    start = std::chrono::high_resolution_clock::now();
    quick_sort(data_quick);
    end = std::chrono::high_resolution_clock::now();
    auto duration_quick = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Bubble Sort Time: " << duration_bubble << " ms\n";
    std::cout << "Quick Sort Time: " << duration_quick << " ms\n";

    return 0;
}
