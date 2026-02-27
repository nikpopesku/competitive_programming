#include <iostream>
#include <vector>
#include <ranges>

using namespace std;

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

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
