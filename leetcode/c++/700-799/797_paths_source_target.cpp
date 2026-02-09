#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > allPathsSourceTarget(const vector<vector<int> > &graph) {
        const int n = static_cast<int>(graph.size());
        vector<vector<int> > response;
        vector<int> path;
        path.push_back(0);
        dfs(0, graph, n, path, response);
        return response;
    }

private:
    void dfs(const int start, const vector<vector<int> > &graph, const int end,
             vector<int> &path, vector<vector<int> > &response) {
        if (start == end - 1) {
            response.push_back(path);
            return;
        }
        for (int nei: graph[start]) {
            path.push_back(nei);
            dfs(nei, graph, end, path, response);
            path.pop_back();
        }
    }
};


int main() {
    auto s = Solution();

    const vector<vector<int> > graph = {{1, 2}, {3}, {3}, {}};
    for (const auto &elem: s.allPathsSourceTarget(graph)) {
        for (const auto e: elem) {
            cout << e << ' ';
        }

        cout << '\n';
    }

    const vector<vector<int> > graph2 = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    for (const auto &elem: s.allPathsSourceTarget(graph2)) {
        for (const auto e: elem) {
            cout << e << ' ';
        }

        cout << '\n';
    }
}
