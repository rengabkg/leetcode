#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    Solution() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *start = new ListNode();
        ListNode *curNode = start;
        int carry = 0;

        while (true) {
            if (l1) {
                carry += l1->val;
            }
            if (l2) {
                carry += l2->val;
            }
            curNode->val = carry % 10;
            carry = carry / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }

            if (!l1 && !l2) {
                break;
            }
            curNode->next = new ListNode();
            curNode = curNode->next;
        }
        if (carry != 0) {
            curNode->next = new ListNode(carry);
        }
        return start;
    }
};
