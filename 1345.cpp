#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int minJumps(const vector<int> &arr) {
        const int n = arr.size();

        // Precompute presence of array elements in array indices.
        unordered_map<int, vector<int>> presence;
        for (int i = n - 1; i >= 0; --i) {
            presence[arr[i]].push_back(i);
        }

        // Distance of each index from the first index.
        vector<int> distance(n, INT_MAX);
        distance[0] = 0;
        // Perform BFS starting from the first index.
        queue<int> exploring;
        exploring.push(0);
        // Start BFS.
        while (!exploring.empty()) {
            const int i = exploring.front();
            const int dist_i = distance[i];
            exploring.pop();

            if (i == n - 1) {
                // BFS has reached the last index. We can stop.
                break;
            }

            // Explore moving to the left.
            if (i - 1 >= 0 && distance[i - 1] > dist_i + 1) {
                distance[i - 1] = dist_i + 1;
                exploring.push(i - 1);
            }

            // Explore moving to the right.
            if (i + 1 < n && distance[i + 1] > dist_i + 1) {
                distance[i + 1] = dist_i + 1;
                exploring.push(i + 1);
            }

            // Explore moving to the indices with the same element.
            for (const int j : presence[arr[i]]) {
                if (distance[j] > dist_i + 1) {
                    distance[j] = dist_i + 1;
                    exploring.push(j);
                }
            }
            // We don't want to explore these indices again in the future. If we
            // don't do this, complexity will be O(n^2) and we'll get TLE.
            presence[arr[i]].clear();
        }

        return distance[n - 1];
    }
};
