#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set> // Or vector + unique

using namespace std;

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> moves;
    // Precompute moves
    for (int dx = 0; dx * dx <= M; ++dx) {
        int dy_sq = M - dx * dx;
        if (dy_sq < 0) continue;
        int dy = static_cast<int>(sqrt(dy_sq) + 0.5); // Add 0.5 for rounding before truncating
        if (static_cast<long long>(dy) * dy == dy_sq) {
            // Found valid (dx, dy)
            // Add all unique combinations (±dx, ±dy)
            set<pair<int, int>> current_moves;
            current_moves.insert({dx, dy});
            current_moves.insert({dx, -dy});
            current_moves.insert({-dx, dy});
            current_moves.insert({-dx, -dy});
            for(auto move : current_moves) {
                moves.push_back(move);
            }
        }
    }
    // Remove duplicates if using vector instead of set during generation
    // sort(moves.begin(), moves.end());
    // moves.erase(unique(moves.begin(), moves.end()), moves.end());


    vector<vector<int>> leap(N, vector<int>(N, -1));
    leap[0][0] = 0;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        auto [r1, c1] = q.front(); // C++17 structured binding
        q.pop();

        for (auto [dx, dy] : moves) {
            int r2 = r1 + dx;
            int c2 = c1 + dy;

            // Check bounds
            if (r2 >= 0 && r2 < N && c2 >= 0 && c2 < N) {
                // Check visited
                if (leap[r2][c2] == -1) {
                    leap[r2][c2] = leap[r1][c1] + 1;
                    q.push({r2, c2});
                }
            }
        }
    }

    // Output
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << leap[i][j] << (j == N - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}