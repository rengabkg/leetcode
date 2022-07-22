#include <string>

using namespace std;

class Solution {
  public:
    string longestPalindrome(const string s) {
        const int n = s.size();
        // Tracks the substring which is the longest palindrome.
        // Stores (start index, substring length).
        pair<int, int> solution = {0, 1};

        // Lambda to extend a palindromic substring. Assumes s[left..right] is a
        // palindrome.
        const auto &extendPalindrome = [&s, n](int left,
                                               int right) -> pair<int, int> {
            while (left > 0 && right < n - 1 && s[left - 1] == s[right + 1]) {
                --left;
                ++right;
            }
            // Return the (start index, substring length) of the palindromic
            // substring after extension.
            return {left, right - left + 1};
        };

        // Find palindromic substrings of odd length.
        for (int i = 0; i < n; ++i) {
            const auto t = extendPalindrome(i, i);
            if (solution.second < t.second) {
                solution = t;
            }
        }

        // Find palindromic substrings of even length.
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] != s[i + 1]) {
                continue;
            }
            const auto t = extendPalindrome(i, i + 1);
            if (solution.second < t.second) {
                solution = t;
            }
        }

        return s.substr(solution.first, solution.second);
    }
};
