#include <vector>

using namespace std;

class Solution {
  public:
    int trapRainWater(const vector<int> &heights) {
        const int n = heights.size();

        int vol = 0;

        // Left and right pointers.
        int left = 0, right = n - 1;
        // Track maximum to the left and right of left and right pointers resp.
        int left_max = 0, right_max = 0;
        while (left <= right) {
            // If the following condition holds, we can be sure that left_max
            // will be less than the maximum to the right of left pointer.
            if (left_max < right_max) {
                if (heights[left] >= left_max) {
                    left_max = heights[left];
                } else {
                    vol += left_max - heights[left];
                }
                ++left;
            } else {
                if (heights[right] >= right_max) {
                    right_max = heights[right];
                } else {
                    vol += right_max - heights[right];
                }
                --right;
            }
        }

        return vol;
    }
};
