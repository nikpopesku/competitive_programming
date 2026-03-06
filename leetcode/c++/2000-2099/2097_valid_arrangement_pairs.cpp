#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <array>

using namespace std;

void dfs(const int node, const int parent, vector<vector<int> > &adj, vector<vector<int>> &result) {
    while (!adj[node].empty()) {
        const auto e = adj[node].back();
        adj[node].pop_back();

        dfs(e, node, adj, result);
    }

    if (parent != -1) {
        result.push_back({parent, node});
    }
}

class Solution {
public:
    vector<vector<int> > validArrangement(const vector<vector<int> > &pairs) {
        int n = pairs[0][0];
        for (auto &p: pairs) {
            n = max(n, p[0]);
            n = max(n, p[1]);
        }
        vector outdegree(n + 1, 0);
        vector indegree(n + 1, 0);
        vector adj(n + 1, vector<int>());

        for (auto &p: pairs) {
            ++outdegree[p[0]];
            ++indegree[p[1]];
            adj[p[0]].push_back(p[1]);
        }

        int start = -1;
        for (int i = 1; i <= n; ++i) {
            if (outdegree[i] - indegree[i] == 1) {
                start = i;
                break;
            }
        }

        vector<vector<int>> result;

        dfs(start, -1, adj, result);
        ranges::reverse(result);

        return result;
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > pairs = {{5, 1}, {4, 5}, {11, 9}, {9, 4}};
    for (auto &e: s.validArrangement(pairs)) {
        cout << e[0] << ' ' << e[1] << '\n';
    }
}
