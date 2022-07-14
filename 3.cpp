#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(const string s) {
        const int n = s.size();

        // Maintains the last index for characters seen so far.
        unordered_map<char, int> last_seen;
        last_seen.reserve(256);

        int longest_substr_length = 0;

        // Maintains the start of the current valid substring.
        int left = 0;
        for (int i = 0; i < n; i++) {
            if (last_seen.find(s[i]) != last_seen.end() &&
                last_seen[s[i]] >= left) {
                left = last_seen[s[i]] + 1;
            }

            longest_substr_length = max(longest_substr_length, i - left + 1);
            last_seen[s[i]] = i;
        }

        return longest_substr_length;
    }
};
