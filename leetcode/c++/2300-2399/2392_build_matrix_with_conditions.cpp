#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> buildMatrix(const int k, const vector<vector<int>>& rowConditions, const vector<vector<int>>& colConditions) {
        const vector<int> col_order = topsort(k, colConditions);
        vector<int> row_order = topsort(k, rowConditions);

        if (col_order.empty() || row_order.empty()) return {{}};

        vector<int> row_pos(k+1);
        vector<int> col_pos(k+1);
        for (int i = 0; i < k; ++i) {
            row_pos[row_order[i]] = i;
        }
        for (int i = 0; i < k; ++i) {
            col_pos[col_order[i]] = i;
        }
        vector response(k, vector<int>(k, 0));

        for (int i = 1; i <= k; ++i) {
            response[row_pos[i]][col_pos[i]] = i;
        }

        return response;
    }
private:
    vector<int> topsort(const int k, const vector<vector<int>>&conditions) {
        vector adj(k + 1, vector<int>());
        vector<int> indegree(k + 1, 0);

        for (auto &c: conditions) {
            adj[c[0]].push_back(c[1]);
            ++indegree[c[1]];
        }

        vector<int> response;
        queue<int> q;

        for (int i = 1; i <= k; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            auto e = q.front();
            q.pop();

            response.push_back(e);

            for (auto &nei: adj[e]) {
                if (--indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        if (response.size() != k) return   {};

        return response;
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
