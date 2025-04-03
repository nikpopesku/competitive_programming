#include <bits/stdc++.h>

using namespace std;

int N, M;

void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &vc) {
    visited[i][j] = true;

    for (auto &dx: {-1, 0, 1}) {
        for (auto &dy: {-1, 0, 1}) {
            if (dx + dy == 1 and i + dx >= 0 and i + dx < 4 * N and j + dy >= 0 and j + dy < 4 * M and
                !visited[i + dx][j + dy] && vc[i + dx][i + dy]) {
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

    vector vc(4 * N, vector<int>(4 * M, 1));
    vector visited(4 * N, vector<bool>(4 * M, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int vi = i * 4; vi < i * 4 + 4; ++vi) {
                for (int vj = j * 4; vj < j * 4 + 4; ++vj) {
                    if (S[i][j] == '\\' && vi - 4 * i == vj - 4 * j) {
                        vc[vi][vj] = 0;
                        continue;
                    }
                    if (S[i][j] == '/' && vi + vj == i * 4 + j * 4 + 3) {
                        vc[vi][vj] = 0;
                    }
                }
            }
        }
    }

    int response = 0;

    for (int i = 0; i < 4 * N; ++i) {
        for (int j = 0; j < 4 * M; ++j) {
            cout << vc[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < 4 * N; ++i) {
        for (int j = 0; j < 4 * M; ++j) {
            if (!visited[i][j]) {
                dfs(i, j, visited, vc);
                ++response;
            }
        }
    }

    cout << response << "\n";
}