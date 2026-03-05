#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

constexpr int MOUSE_MOVE = 1;
constexpr int CAT_MOVE = 2;

class Solution {
public:
    int catMouseGame(const vector<vector<int> > &graph) {
        queue<tuple<int, int, int>> q;

        q.push({1, 2, MOUSE_MOVE});

        while (!q.empty()) {
            auto [mouse_position, cat_position, last_move] = q.front();
            q.pop();
            int next_move = last_move == MOUSE_MOVE ? CAT_MOVE : MOUSE_MOVE;

            for (auto nei: graph[next_move]) {
                if (next_move == MOUSE_MOVE and nei == 0) continue;
            }
        }
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > graph = {{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}};
    cout << s.catMouseGame(graph) << endl; //0
}
