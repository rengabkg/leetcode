#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int uniquePathsWithObstacles(const vector<vector<int>> &obstacle_grid) {
        const int m = obstacle_grid.size();
        const int n = obstacle_grid[0].size();

        // Tracks unique paths till (i, j)th cell.
        vector<vector<int>> unique_paths(m, vector<int>(n, 0));

        // Initialize first column.
        for (int i = 0; i < m; ++i) {
            if (obstacle_grid[i][0]) {
                break;
            }
            unique_paths[i][0] = 1;
        }
        // Initialize first row.
        for (int i = 0; i < n; ++i) {
            if (obstacle_grid[0][i]) {
                break;
            }
            unique_paths[0][i] = 1;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacle_grid[i][j]) {
                    continue;
                }
                unique_paths[i][j] =
                    unique_paths[i - 1][j] + unique_paths[i][j - 1];
            }
        }

        return unique_paths[m - 1][n - 1];
    }
};
