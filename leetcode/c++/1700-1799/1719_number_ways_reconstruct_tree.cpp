#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int checkWays(const vector<vector<int> > &pairs) {
        const int n = 500;
        int distinct_nodes = 0;
        vector node(n + 1, false);
        vector<int> parent(n + 1);

        for (auto &p: pairs) {
            if (node[p[0]] == false) {
                ++distinct_nodes;
                node[p[0]] = true;
            }

            if (node[p[1]] == false) {
                ++distinct_nodes;
                node[p[1]] = true;
            }
        }

        vector adj(n + 1, vector<int>());

        for (auto &p: pairs) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        bool no_root = true;
        int ans = 1;
        for (auto &a: adj) {
            if (a.size() == distinct_nodes - 1) {
                if (!no_root) ans = 2;
                no_root = false;
            }
        }

        if (no_root) {
            return 0;
        }

        for (int i = 1; i <= n; ++i) {
            if (adj[i].empty()) continue;
            if (adj[i].size() == distinct_nodes - 1) continue;
            int min_degree = n;
            int parent_index = adj[i][0];

            for (int j = 0; j < adj[i].size(); ++j) {
                if (adj[adj[i][j]].size() < adj[i].size()) continue;
                if (static_cast<int>(adj[adj[i][j]].size()) < min_degree) {
                    parent_index = adj[i][j];
                    min_degree = static_cast<int>(adj[adj[i][j]].size());
                }
            }

            parent[i] = parent_index;
        }

        for (int i = 1; i <= n; ++i) {
            if (adj[i].empty()) continue;
            if (adj[i].size() == distinct_nodes - 1) continue;

            int p = parent[i];

            // count common neighbors of i and p
            vector<bool> in_adj_p(n + 1, false);
            for (auto &a: adj[p]) {
                in_adj_p[a] = true;
            }

            int common = 0;
            for (auto &a: adj[i]) {
                if (a != p && in_adj_p[a]) ++common;
            }

            if (common != static_cast<int>(adj[i].size()) - 1) return 0;

            if (adj[i].size() == adj[p].size()) ans = 2;
        }

        return ans;
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > pairs = {{1, 2}, {2, 3}};
    cout << s.checkWays(pairs) << '\n';

    vector<vector<int> > pairs2 = {{1, 2}, {2, 3}, {1, 3}};
    cout << s.checkWays(pairs2) << '\n';

    vector<vector<int> > pairs3 = {{1, 2}, {2, 3}, {2, 4}, {1, 5}};
    cout << s.checkWays(pairs3) << '\n';
}
