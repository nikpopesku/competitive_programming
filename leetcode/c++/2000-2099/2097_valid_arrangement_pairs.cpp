#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void dfs(int node, int parent, unordered_map<int, vector<int>> &adj, vector<vector<int>> &result) {
    auto &neighbors = adj[node];
    while (!neighbors.empty()) {
        const int e = neighbors.back();
        neighbors.pop_back();
        dfs(e, node, adj, result);
    }
    if (parent != -1) {
        result.push_back({parent, node});
    }
}

class Solution {
public:
    vector<vector<int>> validArrangement(const vector<vector<int>> &pairs) {
        unordered_map<int, int> outdegree, indegree;
        unordered_map<int, vector<int>> adj;

        for (auto &p: pairs) {
            ++outdegree[p[0]];
            ++indegree[p[1]];
            adj[p[0]].push_back(p[1]);
        }

        int start = pairs[0][0];
        for (auto &[node, out]: outdegree) {
            if (out - indegree[node] == 1) {
                start = node;
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

    cout << '\n';

    vector<vector<int> > pairs2 = {{1, 3}, {3, 2}, {2, 1}};
    for (auto &e: s.validArrangement(pairs2)) {
        cout << e[0] << ' ' << e[1] << '\n';
    }

    cout << '\n';

    vector<vector<int> > pairs3 = {{1,2},{1,3},{2,1}};
    for (auto &e: s.validArrangement(pairs3)) {
        cout << e[0] << ' ' << e[1] << '\n';
    }
}
