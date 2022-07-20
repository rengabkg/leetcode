#include <vector>

using namespace std;

class Solution {
  public:
    int maxCoins(const vector<int> &nums_orig) {
        // We can safely ignore zero-valued balloons.
        // Copy non-zero-valued balloons over to a new vector adding 1 at the
        // front and the back.
        vector<int> nums;
        nums.push_back(1);
        copy_if(nums_orig.begin(), nums_orig.end(), back_inserter(nums),
                [](const int i) { return (i != 0); });
        nums.push_back(1);

        // Number of balloons.
        const int n = nums.size() - 2;
        // DP store with padding.
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // Iterate over all subarrays of balloons in increasing order of length.
        for (int length = 1; length <= n; ++length) {
            const int max_left = n - length + 1;
            for (int left = 1; left <= max_left; ++left) {
                const int right = left + length - 1;
                // Iterate over each balloon in the current subarray and treat
                // it as the last balloon to be burst in the subarray.
                for (int lb = left; lb <= right; ++lb) {
                    // Solution computed by DP for subarray to the left of the
                    // current balloon.
                    const int l_val = dp[left][lb - 1];
                    // Solution computed by DP for subarray to the right of the
                    // current balloon.
                    const int r_val = dp[lb + 1][right];
                    // Coins added by bursting the current balloon last.
                    const int lb_burst_val =
                        nums[left - 1] * nums[lb] * nums[right + 1];
                    dp[left][right] =
                        max(dp[left][right], l_val + r_val + lb_burst_val);
                }
            }
        }

        return dp[1][n];
    }
};
