#include <vector>

using namespace std;

class Solution {
  public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        const int n = envelopes.size();

        // Sort the envelopes by increasing width. Envelopes having the same
        // width are sorting by decreasing height. This helps in the LIS
        // algorithm which follows.
        const auto &comp = [](const vector<int> &l, const vector<int> &r) {
            if (l[0] == r[0]) {
                return l[1] > r[1];
            }
            return l[0] < r[0];
        };
        sort(envelopes.begin(), envelopes.end(), comp);

        // Find LIS (Longest Increasing Subsequence) for the heights in the
        // sorted envelopes. This takes O(nlogn) time.
        vector<int> lis;
        lis.push_back(envelopes[0][1]);
        for (int i = 1; i < n; ++i) {
            auto it = lower_bound(lis.begin(), lis.end(), envelopes[i][1]);
            if (it == lis.end()) {
                lis.push_back(envelopes[i][1]);
            } else {
                *it = envelopes[i][1];
            }
        }

        return lis.size();
    }
};
