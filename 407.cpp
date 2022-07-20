#include <array>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    int trapRainWater(const vector<vector<int>> &height_map) {
        const int m = height_map.size();
        const int n = height_map[0].size();

        // Min heap to track current boundary. The boundary block with the
        // minimum heaight will be at the top of heap.
        const auto &comp = [](const array<int, 3> &l, const array<int, 3> &r) {
            return l[0] > r[0];
        };
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(comp)>
            min_heap(comp);
        // Tracks blocks already visited.
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Initialize boundary as outermost blocks.
        for (int i = 0; i < n; ++i) {
            min_heap.push({height_map[0][i], 0, i});
            visited[0][i] = true;
            min_heap.push({height_map[m - 1][i], m - 1, i});
            visited[m - 1][i] = true;
        }
        for (int i = 1; i < m - 1; ++i) {
            min_heap.push({height_map[i][0], i, 0});
            visited[i][0] = true;
            min_heap.push({height_map[i][n - 1], i, n - 1});
            visited[i][n - 1] = true;
        }

        int vol = 0;
        const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!min_heap.empty()) {
            const auto [height, i, j] = min_heap.top();
            min_heap.pop();

            for (const auto &dir : dirs) {
                int x = i + dir[0];
                int y = j + dir[1];
                if (x < 0 || x >= m) {
                    continue;
                }
                if (y < 0 || y >= n) {
                    continue;
                }
                if (visited[x][y]) {
                    continue;
                }

                if (height_map[x][y] < height) {
                    vol += height - height_map[x][y];
                }

                min_heap.push({max(height, height_map[x][y]), x, y});
                visited[x][y] = true;
            }
        }

        return vol;
    }
};
