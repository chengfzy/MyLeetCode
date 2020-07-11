#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace testing;

/**
 * @brief Solution for problem
 */
class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> sumPairs{{nums[0], 0}};
        for (int i = 1; i < nums.size(); ++i) {
            int other = target - nums[i];
            auto it = sumPairs.find(other);
            if (it != sumPairs.end()) {
                return {it->second, i};
            } else {
                // add to pair
                sumPairs[nums[i]] = i;
            }
        }

        // if not found
        return {-1, -1};
    }
};

/**
 * @brief Test 01
 */
TEST(Test, Test01) {
    // test case
    vector<int> nums{2, 7, 11, 15};
    int target{9};
    vector<int> output{0, 1};

    // test
    Solution solution;
    vector<int> ret = solution.twoSum(nums, target);
    EXPECT_THAT(ret, ContainerEq(output));
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}