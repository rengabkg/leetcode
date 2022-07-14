#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<string> generateParenthesis(const int n) {
        vector<string> result;
        // We use a queue to keep track of partially-built strings that have
        // potential to be expanded into valid ones.
        // Each entry in the queue stores a partially-built string along with
        // the number of open and close parentheses in it.
        queue<tuple<string, int, int>> q;
        q.push({"", 0, 0});
        while (!q.empty()) {
            const auto [s, open, close] = q.front();
            q.pop();
            if (open == n && close == n) {
                // We have built a valid string.
                result.push_back(s);
            }
            if (open < n) {
                // We can add an open parenthesis.
                q.push({s + "(", open + 1, close});
            }
            if (close < open) {
                // We can add an close parenthesis.
                q.push({s + ")", open, close + 1});
            }
        }
        return result;
    }
};
