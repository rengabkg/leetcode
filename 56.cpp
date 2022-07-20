#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        // Sort intervals on start point.
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &l, const vector<int> &r) {
                 return l[0] < r[0];
             });

        vector<vector<int>> merged;
        for (const auto &interval : intervals) {
            if (merged.empty() || merged.back()[1] < interval[0]) {
                // We can start building a new interval.
                merged.push_back(interval);
            } else {
                // We can extend the current interval.
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};
