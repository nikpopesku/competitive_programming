#include<bits/stdc++.h>

using namespace std;

#define ll long long

void
dfs(vector<bool> &visited, int city_index, vector<set<int>> &roads, vector<set<int>> &railways,
    vector<int> &response, int &N) {
    visited[city_index] = true;
    ++response[city_index];

    for (int i = 1; i <= N; ++i) {
        if (!visited[i] && railways[city_index].count(i)) {
            dfs(visited, i, roads, railways, response, N);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, L, city1, city2;
    cin >> N >> K >> L;
    vector<set<int>> roads(N + 1);
    vector<set<int>> railways(N + 1);
    vector<int> response(N + 1, 0);
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < K; ++i) {
        cin >> city1 >> city2;

        roads[city1].insert(city2);
        roads[city2].insert(city1);
    }

    for (int i = 0; i < L; ++i) {
        cin >> city1 >> city2;

        railways[city1].insert(city2);
        railways[city2].insert(city1);
    }

    for (int i = 1; i <= N; ++i) {
        if (visited[i]) continue;

        dfs(visited, i, roads, railways, response, N);
    }

    for (int i = 1; i <= N; ++i) cout << response[i] << (i != N ? " " : "\n");
}
