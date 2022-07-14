#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        const int n = nums.size();
        if (n == 1) {
            return;
        }

        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int j = n - 1;
        while (nums[j] <= nums[i]) {
            --j;
        }

        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};
