#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool carPooling(vector<vector<int>> &trips, const int capacity) {
        // Sort trips on starting point.
        sort(trips.begin(), trips.end(),
             [](const vector<int> &l, const vector<int> &r) {
                 return l[1] < r[1];
             });

        // Min heap tracking passengers currenty travelling in the car.
        // Passengers getting down early will get heap priority. Each entry in
        // the heap will be of the form (drop point, num passengers).
        const auto &comp = [](const pair<int, int> &l,
                              const pair<int, int> &r) {
            return l.first > r.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)>
            passengers_travelling(comp);

        int num_passengers = 0;
        for (const auto &trip : trips) {
            while (!passengers_travelling.empty() &&
                   passengers_travelling.top().first <= trip[1]) {
                num_passengers -= passengers_travelling.top().second;
                passengers_travelling.pop();
            }
            num_passengers += trip[0];
            if (num_passengers > capacity) {
                return false;
            }
            passengers_travelling.push({trip[2], trip[0]});
        }
        return true;
    }
};
