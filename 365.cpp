#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool canMeasureWater(const int jug1Capacity, const int jug2Capacity,
                         const int targetCapacity) {
        if (targetCapacity == 0) {
            return true;
        }
        if (targetCapacity > jug1Capacity + jug2Capacity) {
            return false;
        }

        // Lambda for Euler's GCD algorithm.
        const auto &gcd = [](int m, int n) {
            while (n != 0) {
                int t = m % n;
                m = n;
                n = t;
            }
            return m;
        };

        return (targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0);
    }
};
