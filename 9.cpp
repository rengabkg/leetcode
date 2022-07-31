#include <climits>

using namespace std;

class Solution {
  public:
    bool isPalindrome(const int x) {
        // Negative numbers are not palindromes.
        if (x < 0) {
            return false;
        }
        // Single digit numbers are trivialy palindromes.
        if (x < 10) {
            return true;
        }

        // Find reverse and compare for the rest.
        long long tx = x;
        long long rev = 0;
        while (tx) {
            rev = rev * 10 + tx % 10;
            if (rev > INT_MAX) {
                return false;
            }
            tx /= 10;
        }

        return (int)rev == x;
    }
};
