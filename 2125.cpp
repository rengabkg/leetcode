#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int numberOfBeams(const vector<string> &bank) {
        int beams = 0;
        int last_non_zero_device_count = 0;

        for (const string &str : bank) {
            const int device_count = count(str.begin(), str.end(), '1');
            if (device_count > 0) {
                beams += last_non_zero_device_count * device_count;
                last_non_zero_device_count = device_count;
            }
        }

        return beams;
    }
};
