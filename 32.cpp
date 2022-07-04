#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int longestValidParentheses(const string str) {
        const int n = str.size();

        // Iterate through each character. Always push open parenthesis to the
        // stack. Push closing parenthesis if there is no matching
        // opening parenthesis at the top of the stack, otherwise pop the
        // mathching open parenthesis from the stack. At the end of this
        // operation, the stack will only have parenthesis that could not be
        // matched. We can then use distance between two consecutive unmatched
        // parenthesis to find out the length of the valid parenthesis in
        // between.
        stack<pair<char, int>> stk;
        // Base case.
        stk.push({')', -1});
        for (int i = 0; i < n; ++i) {
            const char c = str[i];
            if (c == '(') {
                stk.push({c, i});
            } else {
                if (!stk.empty() && stk.top().first == '(') {
                    stk.pop();
                } else {
                    stk.push({c, i});
                }
            }
        }

        int max_len = 0;
        int cur = n - 1;
        while (!stk.empty()) {
            int prev = stk.top().second;
            max_len = max(max_len, cur - prev);
            stk.pop();
            cur = prev - 1;
        }

        return max_len;
    }
};
