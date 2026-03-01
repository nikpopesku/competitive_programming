#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int checkWays(const vector<vector<int> > &pairs) {
        const int n = 500;
        int distinct_nodes = 0;
        vector node(n + 1, false);
        vector<int> parent(n+1);

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
            int min_degree = static_cast<int>(adj[adj[i][0]].size());

            for (auto &a: adj[i]) {
                min_degree = min(min_degree, static_cast<int>(adj[a].size()));
            }

            parent[i] = min_degree;
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
