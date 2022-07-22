#include <sstream>
#include <string>

using namespace std;

class Solution {
  public:
    string convert(const string s, const int num_rows) {
        if (num_rows == 1) {
            return s;
        }

        stringstream result;
        // For first row.
        for (int i = 0; i < s.size(); i += 2 * (num_rows - 1)) {
            result << s[i];
        }
        // For middle rows.
        for (int row = 2; row <= num_rows - 1; ++row) {
            const int start = row - 1;
            // Go down vertically (num_rows - row) and then up in zigzag line
            // (num_rows - row).
            const int down_incr = 2 * (num_rows - row);
            // Go up vertically (row - 1) and then down in zigzag line (rew -
            // 1).
            const int up_incr = 2 * (row - 1);

            int i = start;
            bool going_down = true;

            while (i < s.size()) {
                result << s[i];
                if (going_down) {
                    i += down_incr;
                    going_down = false;
                } else {
                    i += up_incr;
                    going_down = true;
                }
            }
        }
        // For last row.
        for (int i = num_rows - 1; i < s.size(); i += 2 * (num_rows - 1)) {
            result << s[i];
        }
        return result.str();
    }
};
