# Word Count

## 專案背景
本專案旨在建立一個簡單的字數統計工具，讀取輸入文字並計算每個單詞出現的次數。

## 功能描述
- 讀取標準輸入的文字。
- 統計並輸出每個單詞的出現次數。

## 使用方法
編譯專案：
```bash
mkdir build
cd build
cmake ..
make
```

## 執行程式：
```bash
./word_count < input.txt
```

## 測試
### 執行單元測試：
```bash
ctest
```