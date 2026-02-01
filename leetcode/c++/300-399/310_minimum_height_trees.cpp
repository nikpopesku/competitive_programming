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

        vector<vector<int> > adj(n);
        vector<int> degree(n, 0);

        for (const auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        int remaining = n;
        while (remaining > 2) {
            int layer = q.size();
            remaining -= layer;
            for (int i = 0; i < layer; i++) {
                int node = q.front();
                q.pop();
                for (int nei : adj[node]) {
                    degree[nei]--;
                    if (degree[nei] == 1) {
                        q.push(nei);
                    }
                }
            }
        }

        vector<int> response;
        while (!q.empty()) {
            response.push_back(q.front());
            q.pop();
        }

        return response.empty() ? vector<int>{0} : response;
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


    vector<vector<int> > c = {{0,1},{0,2},{0,3},{3,4},{4,5}};
    for (const auto elem: s.findMinHeightTrees(6, c)) {
        cout << elem << ' ';
    }
}
