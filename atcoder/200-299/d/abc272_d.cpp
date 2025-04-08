#include <iostream>
#include <cmath>
#include <vector>
#include <queue>


using namespace std;

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> moves;

    for (int dx = 0; dx * dx <= M; ++dx) {
        int sq_dy = M - dx * dx;
        if (sq_dy < 0) continue;
        int dy = static_cast<int>(sqrt(sq_dy) + 0.5);
        if (static_cast<long long>(dy) * dy == sq_dy) {
            moves.push_back({dx, dy});
            moves.push_back({-dx, -dy});
            moves.push_back({dx, -dy});
            moves.push_back({-dx, dy});
        }
    }

    vector leap(N, vector<int>(N, -1));
    leap[0][0] = 0;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        auto [rx, ry] = q.front();
        q.pop();

        for (const auto & move: moves) {
            int dx = rx + move.first;
            int dy = ry + move.second;

            if (dx >= 0 and dx < N and dy >= 0 and dy < N and leap[dx][dy] == -1) {
                leap[dx][dy] = leap[rx][ry] + 1;
                q.push({dx, dy});
            }
        }
    }


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cout << leap[i][j] << (j != N-1 ? " " : "");
        cout << "\n";
    }
}