#include <bits/stdc++.h>

using namespace std;

void dfs(int index, int level, vector<bool> &visited, vector<vector<int>> &adj_list, map<pair<int, int>, int> &R,
         int &counter) {
    visited[index] = true;
    ++counter;

    for (auto &neighbour: adj_list[index]) {
        if (R[{index, neighbour}] >= level and !visited[neighbour]) {
            dfs(neighbour, level, visited, adj_list, R, counter);
        }
    }
}


int main() {
    int N, M, i;

    int val_a, val_b, val_r, min_level = 100000, max_level = 1;

    assert(2 == scanf("%d %d", &N, &M));
    map<pair<int, int>, int> R;
    vector<vector<int>> adj_list(N);

    for (i = 0; i < M; i++) {
        cin >> val_a >> val_b >> val_r;
        adj_list[val_a].push_back(val_b);
        adj_list[val_b].push_back(val_a);
        R[{val_a, val_b}] = val_r;
        if (val_r > max_level) max_level = val_r;
        if (val_r < min_level) min_level = val_r;
    }

    int left = min_level, right = max_level;

    while (left < right) {
        int counter = 0;
        int m = left + (right - left) / 2;
        vector<bool> visited(N, false);
        dfs(0, m, visited, adj_list, R, counter);
        if (counter == N) {
            left = m;
        } else {
            right = m - 1;
        }
    }

    cout << left << "\n";
}
