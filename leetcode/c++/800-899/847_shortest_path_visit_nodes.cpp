#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestPathLength(const vector<vector<int> > &graph) {
        queue<pair<int, int> > q;
        const int n = static_cast<int>(graph.size());
        vector visited(n, vector(1 << n, false));

        for (int i = 0; i < n; ++i) {
            q.emplace(i, 1 << i);
            visited[i][1 << i] = true;
        }

        const int all_visited = (1 << n) - 1;
        int steps = 0;

        while (!q.empty()) {
            int sz = static_cast<int>(q.size());

            while (--sz >= 0) {
                auto [elem, mask] = q.front();
                q.pop();

                if (mask == all_visited) {
                    return steps;
                }

                for (auto nei: graph[elem]) {
                    int new_mask = mask | (1 << nei);
                    if (!visited[nei][new_mask]) {
                        visited[nei][new_mask] = true;
                        q.emplace(nei, new_mask);
                    }
                }
            }

            ++steps;
        }

        return steps;
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > graph = {{1, 2, 3}, {0}, {0}, {0}};
    cout << s.shortestPathLength(graph) << endl; //4
}
