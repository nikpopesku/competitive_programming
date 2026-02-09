#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > allPathsSourceTarget(vector<vector<int> > &graph) {
    }
};


int main() {
    auto s = Solution();

    vector<vector<int> > graph = {{1, 2}, {3}, {3}, {}};
    for (auto elem: s.allPathsSourceTarget(graph)) {
        for (const auto e: elem) {
            cout << e << ' ';
        }

        cout << '\n';
    }
}
