#include <iostream>
#include <queue>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    vector<vector<int> > validArrangement(vector<vector<int> > &pairs) {
        int n = pairs[0][0];
        for (auto &p: pairs) {
            n = max(n, p[0]);
            n = max(n, p[1]);
        }
        vector<int> outdegree(n+1, 0);
        vector<int> indegree(n+1, 0);
        vector<vector<int>> adj(n+1, vector<int>());

        for (auto &p: pairs) {
            ++outdegree[p[0]];
            ++indegree[p[1]];
            adj[p[0]].push_back(p[1]);
        }
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > pairs = {{5, 1}, {4, 5}, {11, 9}, {9, 4}};
    for (auto &e: s.validArrangement(pairs)) {
        cout << e[0] << ' ' << e[1] << '\n';
    }
}
