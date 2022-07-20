#include <vector>

using namespace std;

class Solution {
  public:
    int peakIndexInMountainArray(const vector<int> &arr) {
        int left = 0, right = arr.size() - 1;

        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return -1;
    }
};
