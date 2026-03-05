#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int MOUSE_MOVE = 1;
constexpr int CAT_MOVE = 2;

class Solution {
public:
    int catMouseGame(const vector<vector<int> > &graph) {
        queue<tuple<int, int, int> > q;

        q.push({1, 2, MOUSE_MOVE});
        int count_moves = 0;
        unordered_map<tuple<int, int, int>, bool> visited;

        while (!q.empty()) {
            auto [mouse_position, cat_position, last_move] = q.front();
            q.pop();
            int next_move = last_move == MOUSE_MOVE ? CAT_MOVE : MOUSE_MOVE;

            for (const auto new_move: graph[next_move]) {
                if (next_move == CAT_MOVE and new_move == 0) continue;
                auto state = next_move == MOUSE_MOVE
                     ? tuple{new_move, cat_position, next_move}
                     : tuple{mouse_position, new_move, next_move};
            }

            ++count_moves;
        }
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > graph = {{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}};
    cout << s.catMouseGame(graph) << endl; //0
}
