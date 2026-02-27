#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> mst;

        sort(edges.begin(), edges.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });
    }
};

int main() {
    auto s = Solution();

    vector<vector<string> > edges = {{0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}};

    for (auto &e: s.findCriticalAndPseudoCriticalEdges(5, edges)) {
        cout << e << ' '; //[[0,1],[2,3,4,5]]
    }

    // cout << '\n';
}
