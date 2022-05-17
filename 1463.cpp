#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int cherryPickup(const vector<vector<int>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // dp[i][j][k] represents the maximum number of cherries the two robots
        // can pick one starting from grid (i, j) and another starting from
        // (i, k).
        vector<vector<vector<int>>> dp(
            rows, vector<vector<int>>(cols, vector<int>(cols)));

        // Initialize dp for last row.
        for (int i = 0; i < cols; ++i) {
            for (int j = i + 1; j < cols; ++j) {
                dp[rows - 1][i][j] = grid[rows - 1][i] + grid[rows - 1][j];
                dp[rows - 1][j][i] = dp[rows - 1][i][j];
            }
        }

        for (int row = rows - 2; row >= 0; --row) {
            for (int i = 0; i < cols; ++i) {
                for (int j = i + 1; j < cols; ++j) {
                    int cur_grid_val = grid[row][i] + grid[row][j];
                    int t = 0;
                    for (int x = i - 1; x <= i + 1; ++x) {
                        for (int y = j - 1; y <= j + 1; ++y) {
                            if (x == y || x < 0 || x >= cols || y < 0 ||
                                y >= cols) {
                                continue;
                            }
                            t = max(t, dp[row + 1][x][y]);
                        }
                    }
                    dp[row][i][j] = cur_grid_val + t;
                    dp[row][j][i] = dp[row][i][j];
                }
            }
        }

        return dp[0][0][cols - 1];
    }
};
