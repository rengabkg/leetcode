#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> partitionLabels(const string s) {
        int n = s.size();

        // Last occurence of each lowercase english alphabet.
        vector<int> last(26, -1);
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
        }

        // Partition lengths needed.
        vector<int> part_lengths;
        // Tracks start index of the current partition.
        int part_start = 0;
        // Tracks rightmost occurence of any character in the current partition.
        int max_last = -1;
        for (int i = 0; i < n; ++i) {
            max_last = max(max_last, last[s[i] - 'a']);
            if (max_last == i) {
                // This means no character in the current partition appears to
                // the right of the current position. We can be greedy and end
                // the partition here.
                part_lengths.push_back(i - part_start + 1);
                part_start = i + 1;
            }
        }
        return part_lengths;
    }
};
