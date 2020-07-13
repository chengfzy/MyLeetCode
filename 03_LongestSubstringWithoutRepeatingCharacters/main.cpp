#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <bitset>
#include <string>

using namespace std;
using namespace testing;

/**
 * @brief Solution for problem
 */
class Solution {
  public:
    /**
     * @brief Sliding window optimized, conside the index i move step
     */
    int lengthOfLongestSubstring(string s) {
        int maxLen{0};
        array<int, 256> charPos;  // the character exist pos
        charPos.fill(-1);

        int i{0}, j{0};
        int n = s.size();
        while (i < n && j < n) {
            int ch = s[j];

            if (charPos[ch] >= i) {
                // calculate the length
                maxLen = max(maxLen, j - i);

                i = max(charPos[ch], i) + 1;  // move more faster
            }

            charPos[ch] = j;
            ++j;
        }

        // calculate the length for while break(i == n or j == n)
        maxLen = max(maxLen, j - i);

        return maxLen;
    }

    /**
     * @brief Sliding window
     */
    int lengthOfLongestSubstring02(string s) {
        int maxLen{0};
        bitset<256> charExist;  // indict whether character exist

        int i{0}, j{0};
        int n = s.size();
        while (i < n && j < n) {
            int ch = s[j];
            if (!charExist[ch]) {
                charExist[ch] = true;
                ++j;

                // calculate the length
                maxLen = max(maxLen, j - i);
            } else {
                charExist[s[i]] = false;
                ++i;
            }
        }

        return maxLen;
    }

    /**
     * @brief Brute force
     */
    int lengthOfLongestSubstring01(string s) {
        int maxLen{0};
        bitset<256> charExist;  // indict whether character exist

        for (int i = 0; i < s.size(); ++i) {
            charExist.reset();

            int j = i;
            for (; j < s.size(); ++j) {
                int ch = s[j];
                if (!charExist[ch]) {
                    charExist[ch] = true;
                } else {
                    break;
                }
            }

            // calculate the length
            maxLen = max(maxLen, j - i);
        }

        return maxLen;
    }
};

/**
 * @brief Test 01
 */
TEST(Test, Test01) {
    // test case
    string s{"abcabcbb"};
    // string s{"abccbb"};

    // test
    Solution solution;
    EXPECT_EQ(solution.lengthOfLongestSubstring(s), 3);
}

/**
 * @brief Test 02
 */
TEST(Test, Test02) {
    // test case
    string s{"bbbb"};

    // test
    Solution solution;
    EXPECT_EQ(solution.lengthOfLongestSubstring(s), 1);
}

/**
 * @brief Test 03
 */
TEST(Test, Test03) {
    // test case
    string s{"pwwkew"};

    // test
    Solution solution;
    EXPECT_EQ(solution.lengthOfLongestSubstring(s), 3);
}

/**
 * @brief Test 04
 */
TEST(Test, Test04) {
    // test case
    string s{"a"};

    // test
    Solution solution;
    EXPECT_EQ(solution.lengthOfLongestSubstring(s), 1);
}

/**
 * @brief Test 05
 */
TEST(Test, Test05) {
    // test case
    string s{"tmmzuxt"};

    // test
    Solution solution;
    EXPECT_EQ(solution.lengthOfLongestSubstring(s), 5);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}