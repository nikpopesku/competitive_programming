#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumScore(const vector<int> &scores, const vector<vector<int> > &edges) {
        const int n = static_cast<int>(scores.size());
        vector adj(n, vector<int>());

        for (auto &e: edges) {
            for (auto [u, v]: {pair{e[0], e[1]}, pair{e[1], e[0]}}) {
                adj[u].push_back(v);
                sort(adj[u].begin(), adj[u].end(), [&](const int a, const int b) {
                    return scores[a] > scores[b];
                });
            }
        }

        int answer = -1;

        for (auto &e: edges) {
            for (const auto &a: adj[e[0]]) {
                if (a == e[1]) continue;

                for (const auto &d: adj[e[1]]) {
                    if (d == a || d == e[0]) continue;

                    answer = max(answer, scores[e[0]] + scores[e[1]] + scores[a] + scores[d]);
                }
            }
        }
        return answer;
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

    const vector scores3 = {1, 1, 1, 10, 10};
    const vector<vector<int> > edges3 = {{0, 3}, {1, 3}, {2, 4}, {3, 4}, {0, 1}};
    cout << s.maximumScore(scores3, edges3) << endl; //22
}
