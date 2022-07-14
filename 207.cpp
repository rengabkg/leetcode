#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool canFinish(const int num_courses,
                   const vector<vector<int>> &prerequisites) {
        // Build edge list and in-degree count for each node.
        vector<vector<int>> edge_list(num_courses);
        vector<int> in_degree(num_courses, 0);
        for (const auto &p : prerequisites) {
            edge_list[p[1]].push_back(p[0]);
            ++in_degree[p[0]];
        }

        // Use Kahn's algorithm for topological sorting.
        // Tracks number of nodes not added to topologically sorted list yet.
        int unsorted_nodes = num_courses;
        queue<int> q;
        for (int i = 0; i < num_courses; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            const int n = q.front();
            q.pop();
            --unsorted_nodes;
            for (const int m : edge_list[n]) {
                --in_degree[m];
                if (in_degree[m] == 0) {
                    q.push(m);
                }
            }
        }

        // Return true iff all nodes are added to topologically sorted list.
        return (unsorted_nodes == 0);
    }
};
