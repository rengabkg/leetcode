#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int brokenCalc(const int start_value, const int target) {
        int ops = 0;
        int target_ = target;

        // Make target less than or equal to start value through a sequence of
        // division by 2 and incrementing by 1. We increment by 1 only when the
        // number is odd. Dividing first and then adding to reach start value
        // will always be optimal.
        while (target_ > start_value) {
            ops += 1 + (target_ % 2);
            target_ = (target_ + 1) / 2;
        }
        ops += start_value - target_;
        return ops;
    }
};
