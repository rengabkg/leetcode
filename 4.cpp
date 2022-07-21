#include <vector>

using namespace std;

class Solution {
  public:
    double findMedianSortedArrays(const vector<int> &nums1,
                                  const vector<int> &nums2) {
        const int m = nums1.size();
        const int n = nums2.size();

        // Lambda to find the kth element among elements from both the arrays
        // taken in sorted order. Prunes half the elements from the search at
        // every step leading to logarithmic complexity.
        const function<int(int, int, int)> kthElement =
            [&nums1, &nums2, m, n, &kthElement](const int start1,
                                                const int start2, const int k) {
                // Handle cases when one array is completely pruned.
                if (start1 >= m) {
                    return nums2[start2 + k];
                }
                if (start2 >= n) {
                    return nums1[start1 + k];
                }

                // Base case. Return the minimum among two starting elements as
                // the first element.
                if (k == 0) {
                    return min(nums1[start1], nums2[start2]);
                }

                // We need to prune (k + 1) / 2 elements from the search.
                const int prune = (k + 1) / 2;
                // Last element pruned if pruning happens in the first array.
                const int pivot1 = start1 + prune - 1 < m
                                       ? nums1[start1 + prune - 1]
                                       : INT_MAX;
                // Last element pruned if pruning happens in the second array.
                const int pivot2 = start2 + prune - 1 < n
                                       ? nums2[start2 + prune - 1]
                                       : INT_MAX;

                if (pivot1 < pivot2) {
                    return kthElement(start1 + prune, start2, k - prune);
                }

                return kthElement(start1, start2 + prune, k - prune);
            };

        const int first_value = kthElement(0, 0, (m + n - 1) / 2);
        const int second_value = kthElement(0, 0, (m + n) / 2);
        const double median = (first_value + second_value) / 2.0;
        return median;
    }
};
