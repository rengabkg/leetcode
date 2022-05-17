#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int majorityElement(const vector<int> &nums) {
        // Use Boyer-Moore majority voting algorithm.
        int majority_elem = INT_MIN;
        int majority_elem_count = 0;

        for (const int num : nums) {
            if (majority_elem_count == 0) {
                majority_elem = num;
                ++majority_elem_count;
                continue;
            }
            if (num == majority_elem) {
                ++majority_elem_count;
            } else {
                --majority_elem_count;
            }
        }

        return majority_elem;
    }
};
