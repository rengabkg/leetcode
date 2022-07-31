#include <climits>

using namespace std;

class Solution {
  public:
    int reverse(const int x) {
        int rev = 0;
        int tx = x;

        while (tx) {
            int d = tx % 10;

            // Check for overflow.
            if ((rev > 0 && rev > (INT_MAX - d) / 10) ||
                (rev < 0 && rev < (INT_MIN - d) / 10)) {
                return 0;
            }

            rev = rev * 10 + d;

            tx = tx / 10;
        }

        return rev;
    }
};
