#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int checkWays(vector<vector<int> > &pairs) {
        int n = 500;
        int distinct_nodes = 0;
        vector<bool> node;

        for (auto &p: pairs) {
            if (node[p[0]] == false) {
                ++distinct_nodes;
                node[p[0]] = true;
            }

            if (node[p[1] == false]) {
                ++distinct_nodes;
                node[p[1]] = true;
            }
        }

        vector adj(n + 1, vector<int>());

        for (auto &p: pairs) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > pairs = {{1, 2}, {2, 3}};
    cout << s.checkWays(pairs) << '\n';

    vector<vector<int> > pairs2 = {{1, 2}, {2, 3}, {1, 3}};
    cout << s.checkWays(pairs2) << '\n';

    vector<vector<int> > pairs3 = {{1, 2}, {2, 3}, {2, 4}, {1, 5}};
    cout << s.checkWays(pairs3) << '\n';
}
