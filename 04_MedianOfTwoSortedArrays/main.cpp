#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <numeric>
#include <vector>

using namespace std;
using namespace testing;

/**
 * @brief Solution for problem
 */
class Solution {
  public:
    int findKthElm(vector<int>& nums1, vector<int>& nums2, int k) {
        int le = max(0, int(k - nums2.size())), ri = min(k, int(nums1.size()));
        while (le < ri) {
            int m = le + (ri - le) / 2;
            if (nums2[k - m - 1] > nums1[m]) {
                le = m + 1;
            } else {
                ri = m;
            }
        }
        //循环结束时的位置le即为所求位置，第k小即为max(nums1[le-1]),nums2[k-le-1])，但是由于le可以为0、k,所以
        // le-1或者k-le-1可能不存在所以下面单独判断下
        int nums1LeftMax = le == 0 ? numeric_limits<int>::min() : nums1[le - 1];
        int nums2LeftMax = le == k ? numeric_limits<int>::min() : nums2[k - le - 1];
        return max(nums1LeftMax, nums2LeftMax);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n & 1) {
            return findKthElm(nums1, nums2, (n >> 1) + 1);
        } else {
            return (findKthElm(nums1, nums2, n >> 1) + findKthElm(nums1, nums2, (n >> 1) + 1)) / 2.0;
        }
    }

    double findMedianSortedArrays01(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int sumIJ = (m + n + 1) / 2;  // i+j
        int i0{0}, i1 = m;
        int a0{0}, a1{0}, b0{0}, b1{0};

        while (i0 <= i1) {
            int i = (i0 + i1) / 2;
            int j = sumIJ - i;

            a0 = i == 0 ? numeric_limits<int>::min() : nums1[i - 1];
            a1 = i == m ? numeric_limits<int>::max() : nums1[i];
            b0 = j == 0 ? numeric_limits<int>::min() : nums2[j - 1];
            b1 = j == n ? numeric_limits<int>::max() : nums2[j];

            if (a0 > b1) {
                i1 = i - 1;
            } else if (b0 > a1) {
                i0 = i + 1;
            } else {
                break;
            }
        }

        // calculate the return value
        int maxLeft = max(a0, b0);
        int minRight = min(a1, b1);
        return (m + n) & 1 ? maxLeft : (maxLeft + minRight) / 2.0;
    }
};

TEST(Test, Test01) {
    // test case
    vector<int> nums1{1, 3, 5, 7, 9};
    vector<int> nums2{6, 7, 8, 10, 12};

    // test
    Solution solution;
    EXPECT_EQ(solution.findMedianSortedArrays(nums1, nums2), 7.0);
}

TEST(Test, Test02) {
    // test case
    vector<int> nums1{1, 2, 4, 6};
    vector<int> nums2{3, 4, 5, 7};

    // test
    Solution solution;
    EXPECT_EQ(solution.findMedianSortedArrays(nums1, nums2), 4);
}

TEST(Test, Test03) {
    // test case
    vector<int> nums1{1, 3};
    vector<int> nums2{2};

    // test
    Solution solution;
    EXPECT_EQ(solution.findMedianSortedArrays(nums1, nums2), 2);
}

TEST(Test, Test04) {
    // test case
    vector<int> nums1{1, 2};
    vector<int> nums2{3, 4};

    // test
    Solution solution;
    EXPECT_EQ(solution.findMedianSortedArrays(nums1, nums2), 2.5);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}