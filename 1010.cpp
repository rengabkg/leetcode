#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int numPairsDivisibleBy60(const vector<int> &time) {
        // Computes C(n, 2).
        const auto &combBase2 = [](const int n) {
            return (int)((long long)n * (n - 1) / 2);
        };

        vector<int> mod_count(60, 0);
        for (const int i : time) {
            ++mod_count[i % 60];
        }

        int ans = combBase2(mod_count[0]);
        ans += combBase2(mod_count[30]);
        for (int i = 1; i <= 29; ++i) {
            ans += mod_count[i] * mod_count[60 - i];
        }

        return ans;
    }
};
