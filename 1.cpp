#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(const vector<int> &nums, const int target) {
        const int n = nums.size();

        unordered_map<int, int> index_of;
        index_of.reserve(nums.size());

        for (int i = 0; i < n; ++i) {
            int search_value = target - nums[i];
            if (index_of.find(search_value) != index_of.end()) {
                return {index_of[search_value], i};
            }
            index_of[nums[i]] = i;
        }

        return {-1, -1};
    }
};
