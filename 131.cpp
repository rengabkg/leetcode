#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<string>> partition(const string &str) {
        // Memoize palindrome checks on substrings.
        vector<vector<int>> is_pal(str.size(), vector<int>(str.size(), -1));
        // Lambda to check if a substring is a palindrome.
        const function<bool(int, int)> isPalindrome =
            [&str, &is_pal, &isPalindrome](const int start, const int end) {
                if (is_pal[start][end] != -1) {
                    return is_pal[start][end] == 1;
                }

                if (start >= end) {
                    is_pal[start][end] == 1;
                    return true;
                }

                if (isPalindrome(start + 1, end - 1) &&
                    str[start] == str[end]) {
                    is_pal[start][end] = 1;
                    return true;
                }

                is_pal[start][end] = 0;
                return false;
            };

        // Stores result.
        vector<vector<string>> partitions;
        // Tracks a valid partition being built during BFS.
        vector<string> p;

        function<void(int)> dfs = [&str, &partitions, &p, &isPalindrome,
                                   &dfs](const int start) {
            if (start == str.size()) {
                partitions.push_back(p);
                return;
            }
            for (int i = start; i < str.size(); ++i) {
                if (isPalindrome(start, i)) {
                    p.push_back(str.substr(start, i - start + 1));
                    dfs(i + 1);
                    p.pop_back();
                }
            }
        };
        dfs(0);

        return partitions;
    }
};
