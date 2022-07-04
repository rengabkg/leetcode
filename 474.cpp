#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int findMaxForm(const vector<string> &strs, const int m, const int n) {
        const int s = strs.size();

        // Precompute number of ones in each string.
        vector<int> ones;
        ones.reserve(s);
        for (const string &str : strs) {
            ones.push_back(count(str.begin(), str.end(), '1'));
        }

        // Memoize results of recursion.
        vector<vector<vector<int>>> memoized(
            m + 1, vector<vector<int>>(n + 1, vector<int>(s, -1)));

        // Lambda for the following recursion:
        //      f(i, j, k) - represents the maximum subset size with at most i
        //      0s and j 1s in the string set containing 0th string to kth
        //      string.
        //      f(i, j, k) = max(f(i, j, k - 1),
        //          f(i - 0s in kth string, j - 1s in kth string, k - 1) + 1)
        //      f(i, j, 0) = 1 if 0th string has less than i 0s and j 1s,
        //                  0 otherwise
        const function<int(int, int, int)> maxSubsetSize =
            [&memoized, &strs, &ones, m, n,
             &maxSubsetSize](const int i, const int j, const int k) {
                if (memoized[i][j][k] != -1) {
                    return memoized[i][j][k];
                }

                const int dm = i - (strs[k].size() - ones[k]);
                const int dn = j - ones[k];

                if (k == 0) {
                    memoized[i][j][k] = dm >= 0 && dn >= 0 ? 1 : 0;
                    return memoized[i][j][k];
                }

                if (dm < 0 || dn < 0) {
                    memoized[i][j][k] = maxSubsetSize(i, j, k - 1);
                    return memoized[i][j][k];
                }

                memoized[i][j][k] = max(maxSubsetSize(i, j, k - 1),
                                        1 + maxSubsetSize(dm, dn, k - 1));
                return memoized[i][j][k];
            };

        return maxSubsetSize(m, n, s - 1);
    }
};
