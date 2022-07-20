#include <vector>

using namespace std;

class Solution {
  public:
    int findJudge(const int n, const vector<vector<int>> &trust) {
        vector<int> degree(n, 0);

        for (const vector<int> &t : trust) {
            --degree[t[0] - 1];
            ++degree[t[1] - 1];
        }

        const auto &j = find(degree.begin(), degree.end(), n - 1);
        if (j == degree.end()) {
            return -1;
        }
        return distance(degree.begin(), j) + 1;
    }
};
