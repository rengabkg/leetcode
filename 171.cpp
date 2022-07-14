#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int titleToNumber(const string columnTitle) {
        long long val = 0;
        long long pow = 1;

        for (auto itr = columnTitle.rbegin(); itr != columnTitle.rend();
             ++itr) {
            val += pow * (*itr - 'A' + 1);
            pow = pow * 26;
        }

        return (int)val;
    }
};
