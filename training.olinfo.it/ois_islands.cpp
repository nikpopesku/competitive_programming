#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXN 1000
int R, C;
int M[MAXN][MAXN];

void dfs(int i, int j, vector<vector<bool>> &visited) {
    visited[i][j] = true;

    for (int vertical: {1, -1})
        for (int horizontal: {1, -1})
            if (i + vertical >= 0 and i + vertical < R and j + horizontal >= 0 and j + horizontal < C and
                !visited[i + vertical][j + horizontal] and M[i + vertical][j + horizontal])
                dfs(i + vertical, j + horizontal, visited);
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);




    assert(2 == scanf("%d %d", &R, &C));
    vector visited(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            assert(1 == scanf("%d", &M[i][j]));
            visited[i][j] = false;
        }

    for (int i: {0, R - 1}) {
        for (int j: {0, C - 1}) {
            if (M[i][j]) dfs(i, j, visited);

            visited[i][j] = true;
        }
    }

    int response = 0;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (visited[i][j]) continue;
            if (!M[i][j]) continue;

            dfs(i, j, visited);
            ++response;
        }
    }

    // insert your code here

    printf("%d\n", response); // print the result
    return 0;
}