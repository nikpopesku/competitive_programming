#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
    vector<int> toposort(int k, vector<vector<int> > &conditions) {
        vector<vector<int> > adj(k + 1);
        vector<int> indegree(k + 1, 0);

        for (auto &c: conditions) {
            adj[c[0]].push_back(c[1]);
            ++indegree[c[1]];
        }

        queue<int> q;
        for (int i = 1; i <= k; ++i)
            if (indegree[i] == 0) q.push(i);

        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            for (int nei: adj[node])
                if (--indegree[nei] == 0) q.push(nei);
        }

        if ((int) order.size() != k) return {};
        return order;
    }

public:
    vector<vector<int> > buildMatrix(int k, vector<vector<int> > &rowConditions, vector<vector<int> > &colConditions) {
        auto rowOrder = toposort(k, rowConditions);
        auto colOrder = toposort(k, colConditions);

        if (rowOrder.empty() || colOrder.empty()) return {};

        vector<int> row_pos(k + 1), col_pos(k + 1);
        for (int i = 0; i < k; ++i) row_pos[rowOrder[i]] = i;
        for (int i = 0; i < k; ++i) col_pos[colOrder[i]] = i;

        vector<vector<int> > matrix(k, vector<int>(k, 0));
        for (int v = 1; v <= k; ++v)
            matrix[row_pos[v]][col_pos[v]] = v;

        return matrix;
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > rowConditions = {{1, 2}, {3, 2}};
    vector<vector<int> > colConditions = {{2, 1}, {3, 2}};
    for (auto &e: s.buildMatrix(3, rowConditions, colConditions)) {
        for (auto &f: e) {
            cout << f << ' ';
        }

        cout << '\n';
    }

    cout << '\n';

    vector<vector<int> > rowConditions2 = {{1, 2}, {2, 3}, {3, 1}, {2, 3}};
    vector<vector<int> > colConditions2 = {{2, 1}};
    for (auto &e: s.buildMatrix(3, rowConditions2, colConditions2)) {
        for (auto &f: e) {
            cout << f << ' ';
        }

        cout << '\n';
    }
}
