// test_word_count.cpp
#include <gtest/gtest.h>
#include <sstream>
#include <map>
#include <string>

// 函式可以接受輸入流並回傳單詞統計
std::map<std::string, int> count_words(std::istream &input) {
    std::map<std::string, int> word_map;
    std::string word;
    while (input >> word) {
        ++word_map[word];
    }
    return word_map;
}

TEST(WordCountTest, BasicTest) {
    std::istringstream input("hello world hello");
    std::map<std::string, int> result = count_words(input);
    EXPECT_EQ(result["hello"], 2);
    EXPECT_EQ(result["world"], 1);
}

TEST(WordCountTest, EmptyInput) {
    std::istringstream input("");
    std::map<std::string, int> result = count_words(input);
    EXPECT_TRUE(result.empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
