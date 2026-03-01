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
        for (auto &a: adj) {
            if (a.size() == distinct_nodes - 1) {
                no_root = false;
                break;
            }
        }

        if (no_root) {
            return 0;
        }

        for (int i = 1; i <= n; ++i) {
            if (adj[i].empty()) continue;
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
