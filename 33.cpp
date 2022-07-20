#include <vector>

using namespace std;

class Solution {
  public:
    int search(const vector<int> &nums, int target) {
        // Finds the pivot, ie, the array element with the minimum value.
        const auto &findPivot = [&nums]() {
            int left = 0, right = nums.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (mid > left && nums[mid] < nums[mid - 1]) {
                    return mid;
                }
                if (mid < right && nums[mid] > nums[mid + 1]) {
                    return mid + 1;
                }
                if (nums[mid] > nums[left]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return -1;
        };

        // The usual binary search.
        const auto &binarySearch = [&nums](int left, int right,
                                           const int target) {
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) {
                    return mid;
                }
                if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return -1;
        };

        const int pivot = findPivot();
        // If no pivot is found, perform binary search on the entire array.
        if (pivot == -1) {
            return binarySearch(0, nums.size() - 1, target);
        }
        // If target is at the pivot, return pivot.
        if (nums[pivot] == target) {
            return pivot;
        }
        // If this condition is met, target should be present before pivot.
        if (target >= nums[0]) {
            return binarySearch(0, pivot - 1, target);
        }
        // Target should be present after pivot.
        return binarySearch(pivot + 1, nums.size() - 1, target);
    }
};
