#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int MOUSE_MOVE = 1;
constexpr int CAT_MOVE = 2;

struct TupleHash {
    size_t operator()(const tuple<int, int, int> &t) const {
        auto [a, b, c] = t;
        return hash<long long>()(
            (static_cast<long long>(a) << 40) ^
            (static_cast<long long>(b) << 20) ^
            static_cast<long long>(c)
        );
    }
};

class Solution {
    unordered_map<tuple<int, int, int>, int, TupleHash> memo;

    int solve(const vector<vector<int> > &graph, int mousePos, int catPos, int turn, int moves) {
        if (mousePos == 0) return 1;
        if (mousePos == catPos) return 2;
        if (moves >= 2 * graph.size()) return 0;

        const auto state = make_tuple(mousePos, catPos, turn);
        if (memo.contains(state)) {
            return memo[state];
        }

        int result;
        if (turn == MOUSE_MOVE) {
            result = 2;
            for (const int nextPos: graph[mousePos]) {
                const int subResult = solve(graph, nextPos, catPos, CAT_MOVE, moves + 1);
                if (subResult == 1) {
                    result = 1;
                    break;
                }
                if (subResult == 0) result = 0;
            }
        } else {
            result = 1;
            for (const int nextPos: graph[catPos]) {
                if (nextPos == 0) continue;
                const int subResult = solve(graph, mousePos, nextPos, MOUSE_MOVE, moves + 1);
                if (subResult == 2) {
                    result = 2;
                    break;
                }
                if (subResult == 0) result = 0;
            }
        }

        memo[state] = result;
        return result;
    }

public:
    int catMouseGame(const vector<vector<int> > &graph) {
        memo.clear();
        return solve(graph, 1, 2, MOUSE_MOVE, 0);
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > graph = {{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}};
    cout << s.catMouseGame(graph) << endl; // 0

    vector<vector<int> > graph2 = {{1, 3}, {0}, {3}, {0, 2}};
    cout << s.catMouseGame(graph2) << endl; // 1
}
