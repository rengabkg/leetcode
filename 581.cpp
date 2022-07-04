#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int findUnsortedSubarray(const vector<int> &nums) {
        const int n = nums.size();

        // Compute the minimum to the right of every element.
        vector<int> min_to_the_right(n, INT_MIN);
        int cur_min = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            min_to_the_right[i] = cur_min;
            cur_min = min(cur_min, nums[i]);
        }

        // Compute the first element which is greater than its minimum to the
        // right.
        int left = 0;
        while (nums[left] <= min_to_the_right[left]) {
            ++left;
        }
        // This means the array is already sorted.
        if (left == n - 1) {
            return 0;
        }

        // Compute the maximum to the left of every element, starting from the
        // position next to the left pointer.
        vector<int> max_to_the_left(n, INT_MAX);
        int cur_max = nums[left];
        for (int i = left + 1; i < n; ++i) {
            max_to_the_left[i] = cur_max;
            cur_max = max(cur_max, nums[i]);
        }

        // Compute the last element which is less than its maximum to the left.
        int right = n - 1;
        while (nums[right] >= max_to_the_left[right]) {
            --right;
        }

        return right - left + 1;
    }
};
