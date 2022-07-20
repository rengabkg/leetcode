#include <vector>

using namespace std;

class Solution {
  public:
    int longestIncreasingPath(const vector<vector<int>> &matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();

        const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> dfs_cache(m, vector<int>(n, 0));

        // Lambda for performing DFS from a given cell.
        const function<int(int, int)> dfs = [&matrix, &dfs_cache, &dirs, &dfs,
                                             m, n](const int i, const int j) {
            // Use memoized result if available.
            if (dfs_cache[i][j] != 0) {
                return dfs_cache[i][j];
            }

            // Try searching neighboring cells in all the four directions.
            // We need not maintain cells already visited because if search
            // proceeds from cell A to B, then value at B > value at A. So,
            // search will never reach A from B.
            int max_dist = 1;
            for (const pair<int, int> &dir : dirs) {
                const int ni = i + dir.first;
                const int nj = j + dir.second;

                if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
                    continue;
                }
                if (matrix[ni][nj] <= matrix[i][j]) {
                    continue;
                }

                int dist = 1 + dfs(ni, nj);
                max_dist = max(max_dist, dist);
            }

            // Memoize the result and return.
            dfs_cache[i][j] = max_dist;
            return max_dist;
        };

        // Perform a DFS from each cell to find the longest increasing path from
        // that cell.
        int longest_path = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                longest_path = max(longest_path, dfs(i, j));
            }
        }

        return longest_path;
    }
};
