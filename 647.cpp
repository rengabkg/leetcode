#include <string>

using namespace std;

class Solution {
  public:
    int countSubstrings(const string s) {
        const int n = s.size();
        int count = 0;

        const auto &countPalindromesByExtension = [&s, n](int left, int right) {
            int l_count = 0;
            while (left >= 0 && right < n) {
                if (s[left] == s[right]) {
                    ++l_count;
                } else {
                    break;
                }
                --left;
                ++right;
            }
            return l_count;
        };

        for (int i = 0; i < n; ++i) {
            count += countPalindromesByExtension(i, i + 1);
            count += countPalindromesByExtension(i, i + 2);
        }
        // Account for all substrings of length 1.
        count += n;

        return count;
    }
};
