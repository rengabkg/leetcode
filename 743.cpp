#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int networkDelayTime(const vector<vector<int>> &times, int n, int k) {
        // Build adjacency list.
        vector<pair<int, int>> adj_list[n + 1];
        for (const vector<int> &time : times) {
            const int source = time[0];
            const int dest = time[1];
            const int travel_time = time[2];

            adj_list[source].push_back({dest, travel_time});
        }

        // Perform Dijkstra's from k.
        // Construct a min-heap to store currently exploring vertices.
        // Each entry in the min-heap will be of the form {distance, vertex}.
        const auto &comp = [](const pair<int, int> &l,
                              const pair<int, int> &r) {
            return l.first > r.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)>
            exploring(comp);
        exploring.push({0, k});
        // Tracks distance of each vertex.
        vector<int> distance(n + 1, INT_MAX);
        distance[0] = 0;
        distance[k] = 0;
        // Explore.
        while (!exploring.empty()) {
            const auto [exploring_distance, dest] = exploring.top();
            exploring.pop();

            if (distance[dest] < exploring_distance) {
                continue;
            }

            for (const auto [neighbor, travel_time] : adj_list[dest]) {
                const int possible_distance = exploring_distance + travel_time;
                if (possible_distance < distance[neighbor]) {
                    distance[neighbor] = possible_distance;
                    exploring.push({possible_distance, neighbor});
                }
            }
        }

        // Find the longest distance for all nodes.
        const int max_distance = *max_element(distance.begin(), distance.end());
        return max_distance == INT_MAX ? -1 : max_distance;
    }
};
