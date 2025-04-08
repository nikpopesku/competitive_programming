#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector leap(N, vector<int>(N, -1));
    leap[0][0] = 0;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        auto elem = q.front();
        q.pop();

        for (int i = 0; i < N; ++i) {
            int val = M - (elem.first - i) * (elem.first - i);
            int sq = round(sqrt(val));
            if (val != sq * sq) continue;

            if (sq - elem.second >= 0 and sq - elem.second < N and leap[i][sq - elem.second] == -1) {
                leap[i][sq - elem.second] = leap[elem.first][elem.second] + 1;
                q.push({i, sq - elem.second});
            }
            if (sq + elem.second >= 0 and sq + elem.second < N and leap[i][sq + elem.second] == -1) {
                leap[i][sq + elem.second] = leap[elem.first][elem.second] + 1;
                q.push({i, sq + elem.second});
            }
        }
    }


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cout << leap[i][j] << " ";
        cout << "\n";
    }
}