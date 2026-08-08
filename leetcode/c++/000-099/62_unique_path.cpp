#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector dp(m, vector(n, 1));

        for (int row = 1; row < m; ++row) {
            for (int col = 1; col < n; ++col) {
                dp[row][col] = min(dp[row - 1][col] + 1, dp[row][col - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    auto s = Solution();

    for (const vector<string> st = {"eat", "tea", "tan", "ate", "nat", "bat"}; auto &e: s.groupAnagrams(st)) {
        for (auto &x: e) cout << x << ' ';
        cout << '\n';
    }

    for (const vector<string> st2 = {""}; auto &e: s.groupAnagrams(st2)) {
        for (auto &x: e) cout << x << ' ';
        cout << '\n';
    }

    for (const vector<string> st3 = {""}; auto &e: s.groupAnagrams(st3)) {
        for (auto &x: e) cout << x << ' ';
        cout << '\n';
    }
}
