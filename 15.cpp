#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        const int n = nums.size();

        // Sort the array.
        sort(nums.begin(), nums.end());

        // Finds two-sums in a sorted range given target.
        const auto &twoSum = [&nums](const int start, const int end,
                                     const int target) {
            vector<pair<int, int>> solutions;

            int left = start, right = end;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    solutions.push_back({nums[left], nums[right]});
                    // For avoiding duplicates.
                    while (left < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    // For avoiding duplicates.
                    while (left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }
                    ++left;
                    --right;
                } else if (nums[left] + nums[right] < target) {
                    ++left;
                } else {
                    --right;
                }
            }

            return solutions;
        };

        vector<vector<int>> solutions;

        // Iterate through array elements and for each element, see if there is
        // a viable two-pair in the subarray to the right.
        for (int i = 0; i < n - 2; ++i) {
            const int target = -1 * nums[i];
            for (const auto &two_pair : twoSum(i + 1, n - 1, target)) {
                solutions.push_back({nums[i], two_pair.first, two_pair.second});
            }
            // For avoiding duplicates.
            while (i < n - 2 && nums[i] == nums[i + 1]) {
                ++i;
            }
        }

        return solutions;
    }
};
