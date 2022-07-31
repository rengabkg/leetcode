#include <string>

using namespace std;

class Solution {
  public:
    int myAtoi(const string s) {
        auto it = s.begin();
        bool is_negative = false;

        // Skip whitespace character.
        while (it != s.end() && *it == ' ') {
            ++it;
        }

        // Read '+' or '-', if present.
        if (it != s.end() && (*it == '+' || *it == '-')) {
            if (*it == '-') {
                is_negative = true;
            }
            ++it;
        }

        long long ans = 0;
        // Keep reading digits until a non-digit is found.
        while (it != s.end() && *it >= '0' && *it <= '9') {
            const int d = is_negative ? '0' - *it : *it - '0';
            ans = ans * 10 + d;

            // Clamp within limits.
            if (ans < INT_MIN) {
                ans = INT_MIN;
            }
            if (ans > INT_MAX) {
                ans = INT_MAX;
            }

            ++it;
        }

        return (int)ans;
    }
};
