#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void dfs(const int index, const int level, vector<bool> &visited, const vector<vector<pair<int, int>>> &adj_list,
         int &counter) {
    visited[index] = true;
    ++counter;

    for (const auto &elem: adj_list[index]) {
        int neighbour = elem.first;
        int neighbour_level = elem.second;
        if (neighbour_level >= level && !visited[neighbour]) {
            dfs(neighbour, level, visited, adj_list, counter);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    int val_a, val_b, val_r, min_level = 100000, max_level = 1;

    cin >> N >> M;
    vector<vector<pair<int, int>>> adj_list(N);

    for (int i = 0; i < M; i++) {
        cin >> val_a >> val_b >> val_r;
        adj_list[val_a].emplace_back(val_b, val_r);
        adj_list[val_b].emplace_back(val_a, val_r);
        min_level = min(min_level, val_r);
        max_level = max(max_level, val_r);
    }

    int left = min_level, right = max_level;
    int result = min_level;

    while (left <= right) {
        int counter = 0;
        int m = left + (right - left) / 2;
        vector<bool> visited(N, false);
        dfs(0, m, visited, adj_list, counter);
        if (counter == N) {
            left = m + 1;
            result = m;
        } else {
            right = m - 1;
        }
    }

    cout << result << "\n";
}
