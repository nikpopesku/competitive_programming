#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumScore(const vector<int> &scores, const vector<vector<int> > &edges) {
        const int n = static_cast<int>(scores.size());
        vector adj(n, list<int>());

        for (auto &e: edges) {
            if (adj[e[0]].empty()) {
                adj[e[0]].push_back(e[1]);
                continue;
            }
            for (auto it = adj[e[0]].begin(); it != adj[e[0]].end(); ++it) {
                if (scores[*it] <= scores[e[1]]) {
                    adj[e[0]].insert(it, e[1]);
                }
            }
        }

        int best_response = -1;

        for (auto &e: edges) {
            const int cur = scores[e[0]] + scores[e[1]];

            for (const auto &a: adj[e[0]]) {
                if (a != e[1]) {
                    for (const auto &d: adj[e[1]]) {
                        if (d != e[0] && d != a) {
                            best_response = max(best_response, cur + scores[a] + scores[d]);
                        }
                    }
                }
            }
        }

        return best_response;
    }
};

int main() {
    auto s = Solution();

    const vector scores = {5, 2, 9, 8, 4};
    const vector<vector<int> > edges = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
    cout << s.maximumScore(scores, edges) << endl; //24

    const vector scores2 = {9, 20, 6, 4, 11, 12};
    const vector<vector<int> > edges2 = {{0, 3}, {5, 3}, {2, 4}, {1, 3}};
    cout << s.maximumScore(scores2, edges2) << endl; //-1
}
