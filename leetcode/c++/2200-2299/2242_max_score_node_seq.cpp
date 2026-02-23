#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int> &scores, vector<vector<int> > &edges) {
        const int n = static_cast<int>(scores.size());
        vector adj(n, list<int>());

        for (auto &e: edges) {
            for (auto it = adj[e[0]].begin(); it != adj[e[0]].end(); ++it) {
                if (scores[*it] <= scores[e[1]]) {
                    adj[e[0]].insert(it, e[1]);
                }
            }
        }
    }
};

int main() {
    auto s = Solution();

    vector<int> scores = {5, 2, 9, 8, 4};
    vector<vector<int> > edges = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
    cout << s.maximumScore(scores, edges) << endl; //0
}
