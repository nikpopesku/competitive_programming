#include <iostream>
#include <queue>
#include <vector>
#include <array>

using namespace std;

// Backward induction BFS from terminal states.
// State: (mouse_pos, cat_pos, turn) where turn 0=mouse, 1=cat.
// Propagate win/loss backward; uncolored states are draws.
class Solution {
public:
    int catMouseGame(const vector<vector<int>> &graph) {
        int n = graph.size();
        // result[m][c][t]: 0=draw, 1=mouse wins, 2=cat wins
        vector<vector<array<int, 2>>> result(n, vector<array<int, 2>>(n, {0, 0}));
        // degree[m][c][t]: remaining undetermined moves from this state
        vector<vector<array<int, 2>>> degree(n, vector<array<int, 2>>(n, {0, 0}));

        for (int m = 0; m < n; m++) {
            for (int c = 1; c < n; c++) {
                degree[m][c][0] = graph[m].size();
                for (int next : graph[c])
                    if (next != 0) degree[m][c][1]++;
            }
        }

        queue<tuple<int,int,int>> q;

        // Mouse at hole -> mouse wins
        for (int c = 1; c < n; c++) {
            for (int t = 0; t < 2; t++) {
                result[0][c][t] = 1;
                q.emplace(0, c, t);
            }
        }
        // Cat catches mouse (m==c, m!=0) -> cat wins
        for (int m = 1; m < n; m++) {
            for (int t = 0; t < 2; t++) {
                result[m][m][t] = 2;
                q.emplace(m, m, t);
            }
        }

        while (!q.empty()) {
            auto [m, c, t] = q.front();
            q.pop();
            int res = result[m][c][t];

            // Find predecessors: states that transitioned into (m, c, t)
            if (t == 0) {
                // Previous turn was cat's (t=1 -> t=0). Cat moved from pc to c.
                for (int pc : graph[c]) {
                    if (pc == 0 || result[m][pc][1] != 0) continue;
                    if (res == 2) { // cat wins: cat would pick this move
                        result[m][pc][1] = 2;
                        q.emplace(m, pc, 1);
                    } else if (--degree[m][pc][1] == 0) { // all cat moves lose
                        result[m][pc][1] = 1;
                        q.emplace(m, pc, 1);
                    }
                }
            } else {
                // Previous turn was mouse's (t=0 -> t=1). Mouse moved from pm to m.
                for (int pm : graph[m]) {
                    if (result[pm][c][0] != 0) continue;
                    if (res == 1) { // mouse wins: mouse would pick this move
                        result[pm][c][0] = 1;
                        q.emplace(pm, c, 0);
                    } else if (--degree[pm][c][0] == 0) { // all mouse moves lose
                        result[pm][c][0] = 2;
                        q.emplace(pm, c, 0);
                    }
                }
            }
        }

        return result[1][2][0]; // mouse at 1, cat at 2, mouse's turn
    }
};

int main() {
    auto s = Solution();

    vector<vector<int>> graph = {{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}};
    cout << s.catMouseGame(graph) << endl; // Expected: 0

    vector<vector<int>> graph2 = {{1, 3}, {0}, {3}, {0, 2}};
    cout << s.catMouseGame(graph2) << endl; // Expected: 1

    vector<vector<int>> graph3 = {{5, 6}, {3, 4}, {6}, {1, 4, 5}, {1, 3, 5}, {0, 3, 4, 6}, {0, 2, 5}};
    cout << s.catMouseGame(graph3) << endl; // Expected: 2
}
