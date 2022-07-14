#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int bitwiseComplement(const int n) {
        int all_ones = 1;
        while (n > all_ones) {
            all_ones = (all_ones << 1) + 1;
        }
        return all_ones - n;
    }
};
