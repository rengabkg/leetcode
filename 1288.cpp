#include <vector>

using namespace std;

class Solution {
  public:
    int removeCoveredIntervals(vector<vector<int>> &intervals) {
        // Sort intervals on start point. If two intervals have the same start
        // point, prefer the longer one.
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &l, const vector<int> &r) {
                 if (l[0] != r[0]) {
                     return l[0] < r[0];
                 }
                 return l[1] > r[1];
             });

        // Tracks the number of non-covered intervals.
        int count = 0;
        // Tracks the end point of last non-covered interval.
        int end = -1;
        for (const auto &interval : intervals) {
            if (end < interval[1]) {
                // Previous interval doesn't cover the current one.
                ++count;
                end = interval[1];
            }
        }

        return count;
    }
};
