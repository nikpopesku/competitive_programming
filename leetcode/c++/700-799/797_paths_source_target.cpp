#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > allPathsSourceTarget(const vector<vector<int> > &graph) {
        queue<vector<int> > q;
        const int n = static_cast<int>(graph.size());

        q.push({0});
        vector<vector<int> > response;

        while (!q.empty()) {
            auto v = q.front();
            q.pop();

            if (v.back() == n - 1) {
                response.push_back(v);
            } else {
                for (auto nei: graph[v.back()]) {
                    auto new_v = v;
                    new_v.push_back(nei);
                    q.push(new_v);
                }
            }
        }

        return response;
    }
};


int main() {
    auto s = Solution();

    vector<vector<int> > graph = {{1, 2}, {3}, {3}, {}};
    for (const auto& elem: s.allPathsSourceTarget(graph)) {
        for (const auto e: elem) {
            cout << e << ' ';
        }

        cout << '\n';
    }

    vector<vector<int> > graph2 = {{4,3,1},{3,2,4},{3},{4},{}};
    for (const auto& elem: s.allPathsSourceTarget(graph2)) {
        for (const auto e: elem) {
            cout << e << ' ';
        }

        cout << '\n';
    }
}
