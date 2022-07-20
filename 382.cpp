#include <random>

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
    Solution(ListNode *head) { head_ = head; }

    int getRandom() {
        // Use reservoir sampling.
        ListNode *ptr = head_;
        int sampled_val = ptr->val;
        int i = 2;
        ptr = ptr->next;

        while (ptr) {
            if (rand() % i == 0) {
                sampled_val = ptr->val;
            }
            i++;
            ptr = ptr->next;
        }

        return sampled_val;
    }

  private:
    ListNode *head_;
};
