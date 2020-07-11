#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace std;
using namespace testing;

/**
 * @brief Definition for singly-linked list
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/**
 * @brief Solution for problem
 */
class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum{0};  // sum number, init with the carry number
        ListNode* ll1 = l1;
        ListNode* ll2 = l2;
        ListNode* ret = new ListNode();  // return list
        ListNode* rr = ret;
        bool run{true};  // flag to indict go on cycle
        while (run) {
            if (ll1 != nullptr) {
                sum += ll1->val;
            }
            if (ll2 != nullptr) {
                sum += ll2->val;
            }

            // save current result
            rr->val = sum % 10;
            sum = sum / 10;

            // still run
            run = sum != 0;

            // move to next node
            if (ll1 != nullptr) {
                ll1 = ll1->next;
                run |= ll1 != nullptr;
            }
            if (ll2 != nullptr) {
                ll2 = ll2->next;
                run |= ll2 != nullptr;
            }

            if (run) {
                rr->next = new ListNode;
                rr = rr->next;
            }
        }
        return ret;
    }

    ListNode* addTwoNumbers01(ListNode* l1, ListNode* l2) {
        int carry{0};  // carry number
        ListNode* ll1 = l1;
        ListNode* ll2 = l2;
        ListNode* ret = new ListNode();  // return list
        ListNode* rr = ret;
        bool run{true};  // flag to indict go on cycle
        while (run) {
            int sum = carry;
            if (ll1 != nullptr) {
                sum += ll1->val;
            }
            if (ll2 != nullptr) {
                sum += ll2->val;
            }

            // save current result
            rr->val = sum % 10;
            carry = sum / 10;

            // still run
            run = carry != 0;

            // move to next node
            if (ll1 != nullptr) {
                ll1 = ll1->next;
                run |= ll1 != nullptr;
            }
            if (ll2 != nullptr) {
                ll2 = ll2->next;
                run |= ll2 != nullptr;
            }

            if (run) {
                rr->next = new ListNode;
                rr = rr->next;
            }
        }
        return ret;
    }
};

/**
 * @brief Test 01
 */
TEST(Test, Test01) {
    // test case
    // l1: 2->4->3
    ListNode* l1a = new ListNode(3);
    ListNode* l1b = new ListNode(4, l1a);
    ListNode* l1 = new ListNode(2, l1b);
    // l2: 4->6->4
    ListNode* l2a = new ListNode(4);
    ListNode* l2b = new ListNode(6, l2a);
    ListNode* l2 = new ListNode(5, l2b);
    // output: 7->0->8
    ListNode* ra = new ListNode(8);
    ListNode* rb = new ListNode(0, ra);
    ListNode* result = new ListNode(7, rb);

    // test
    Solution solution;
    ListNode* ret = solution.addTwoNumbers(l1, l2);
    // check result
    ListNode* x = result;
    ListNode* y = ret;
    while (x != nullptr || y != nullptr) {
        EXPECT_EQ(x->val, y->val);
        x = x->next;
        y = y->next;
    }

    // release memory
    delete l1a;
    delete l1b;
    delete l1;
    delete l2a;
    delete l2b;
    delete l2;
    delete ra;
    delete rb;
    delete result;
    delete ret;
}

/**
 * @brief Test 02
 */
TEST(Test, Test02) {
    // test case
    // l1: 9->9
    ListNode* l1a = new ListNode(9);
    ListNode* l1 = new ListNode(9, l1a);
    // l2: 1
    ListNode* l2 = new ListNode(1);
    // output: 0->0->1
    ListNode* ra = new ListNode(1);
    ListNode* rb = new ListNode(0, ra);
    ListNode* result = new ListNode(0, rb);

    // test
    Solution solution;
    ListNode* ret = solution.addTwoNumbers(l1, l2);
    // check result
    ListNode* x = result;
    ListNode* y = ret;
    while (x != nullptr || y != nullptr) {
        EXPECT_EQ(x->val, y->val);
        x = x->next;
        y = y->next;
    }

    // release memory
    delete l1;
    delete l2;
    delete ra;
    delete result;
    delete ret;
}

/**
 * @brief Test 03
 */
TEST(Test, Test03) {
    // test case
    // l1:
    ListNode* l1 = nullptr;
    // l2: 0, 1
    ListNode* l2a = new ListNode(0);
    ListNode* l2 = new ListNode(1, l2a);
    // output: 0->1
    ListNode* ra = new ListNode(0);
    ListNode* result = new ListNode(1, ra);

    // test
    Solution solution;
    ListNode* ret = solution.addTwoNumbers(l1, l2);
    // check result
    ListNode* x = result;
    ListNode* y = ret;
    while (x != nullptr || y != nullptr) {
        EXPECT_EQ(x->val, y->val);
        x = x->next;
        y = y->next;
    }

    // release memory
    delete l1;
    delete l2;
    delete ra;
    delete result;
    delete ret;
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}