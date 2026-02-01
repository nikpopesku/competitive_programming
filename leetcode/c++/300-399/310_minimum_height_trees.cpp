#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(const int n, const vector<vector<int> > &edges) {
        if (n == 1) {
            return {0};
        }

        vector<vector<int>> adj;
        vector degree(n, 0);

        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            ++degree[e[0]];
            ++degree[e[1]];
        }

        int remaining = n;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        while (remaining > 2) {
            const int layer = static_cast<int>(q.size());
            remaining -= layer;

            for (int i = 0; i < layer; ++i) {
                const auto e = q.front();
                q.pop();

                for (auto nei: adj[e]) {
                    --degree[nei];

                    if (degree[nei] == 1) {
                        q.push(nei);
                    }
                }
            }
        }
    }
};

int main() {
    Solution s; //{1}
    vector<vector<int> > a = {{1, 0}, {1, 2}, {1, 3}};

    for (const auto elem: s.findMinHeightTrees(4, a)) {
        cout << elem << ' ';
    }
    cout << '\n';


    vector<vector<int> > b = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}}; //{3,4}
    for (const auto elem: s.findMinHeightTrees(6, b)) {
        cout << elem << ' ';
    }
    cout << '\n';


    vector<vector<int> > c = {{0, 1}, {0, 2}, {0, 3}, {3, 4}, {4, 5}};
    for (const auto elem: s.findMinHeightTrees(6, c)) {
        cout << elem << ' ';
    }
}
