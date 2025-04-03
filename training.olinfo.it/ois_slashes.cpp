#include <bits/stdc++.h>

using namespace std;

int N, M;

void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &vc) {
    visited[i][j] = true;

    for (auto &dx: {-1, 0, 1}) {
        for (auto &dy: {-1, 0, 1}) {
            if (abs(dx) + abs(dy) == 1 and i + dx >= 0 and i + dx < 3 * N and j + dy >= 0 and j + dy < 3 * M and
                !visited[i + dx][j + dy] && vc[i + dx][j + dy]) {
                dfs(i + dx, j + dy, visited, vc);
            }
        }
    }
}

int main() {

    vector<string> S;
    cin >> N >> M;
    S.resize(N);

    for (int i = 0; i < N; i++)
        cin >> S[i];

    vector vc(3 * N, vector<int>(3 * M, 1));
    vector visited(3 * N, vector<bool>(3 * M, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int vi = i * 3; vi < i * 3 + 3; ++vi) {
                for (int vj = j * 3; vj < j * 3 + 3; ++vj) {
                    if (S[i][j] == '\\' && vi - 3 * i == vj - 3 * j) {
                        vc[vi][vj] = 0;
                        continue;
                    }
                    if (S[i][j] == '/' && vi + vj == i * 3 + j * 3 + 2) {
                        vc[vi][vj] = 0;
                    }
                }
            }
        }
    }

    int response = 0;

    for (int i = 0; i < 3 * N; ++i) {
        for (int j = 0; j < 3 * M; ++j) {
            if (!visited[i][j] and vc[i][j]) {
                dfs(i, j, visited, vc);
                ++response;
            }
        }
    }

    cout << response << "\n";
}