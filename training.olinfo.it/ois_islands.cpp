#include <bits/stdc++.h>

using namespace std;

int R, C;


void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &M) {
    visited[i][j] = true;

    for (int vertical: {1, 0, -1})
        for (int horizontal: {1, 0, -1})
            if (abs(horizontal) + abs(vertical) < 2 and i + vertical >= 0 and i + vertical < R and
                j + horizontal >= 0 and j + horizontal < C and
                !visited[i + vertical][j + horizontal] and M[i + vertical][j + horizontal])
                dfs(i + vertical, j + horizontal, visited, M);
}

int main() {
    assert(2 == scanf("%d %d", &R, &C));
    vector visited(R, vector<bool>(C, false));
    vector M(R, vector<int>(C, 0));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            assert(1 == scanf("%d", &M[i][j]));
            visited[i][j] = false;
        }
    }

    for (int i: {0, R - 1}) {
        for (int j = 0; j < C; ++j) {
            if (M[i][j] and !visited[i][j]) dfs(i, j, visited, M);

            visited[i][j] = true;
        }
    }

    for (int i = 0; i < R; ++i) {
        for (int j: {0, C - 1}) {
            if (M[i][j] and !visited[i][j]) dfs(i, j, visited, M);

            visited[i][j] = true;
        }
    }

    int response = 0;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (visited[i][j]) continue;
            if (!M[i][j]) continue;

            dfs(i, j, visited, M);
            ++response;
        }
    }

    printf("%d\n", response);
}