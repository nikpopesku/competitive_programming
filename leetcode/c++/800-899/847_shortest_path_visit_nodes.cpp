#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int> > &graph) {
        queue<pair<int, int> > q;
        const int n = static_cast<int>(graph.size());
        vector visited(n, vector<bool>(1 << n, false));

        for (int i = 0; i < n; ++i) {
            q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }

        int steps = 0;
        const int all_visited = (1 << n) - 1;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [node, mask] = q.front();
                q.pop();

                if (mask == all_visited) return steps;

                for (int neighbor: graph[node]) {
                    int new_mask = mask | (1 << neighbor);
                    if (!visited[neighbor][new_mask]) {
                        visited[neighbor][new_mask] = true;
                        q.push({neighbor, new_mask});
                    }
                }
            }
            steps++;
        }

        return 0;
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > graph = {{1, 2, 3}, {0}, {0}, {0}};
    cout << s.shortestPathLength(graph) << endl; //4
}
