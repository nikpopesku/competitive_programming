#include<bits/stdc++.h>

using namespace std;

#define ll long long

void
dfs(vector<bool> &visited, int city_index, vector<set<int>> &roads, vector<set<int>> &railways, vector<int> &response) {
    visited[city_index] = true;
    ++response[city_index];

    for (size_t i = 0; i < roads[city_index].size(); ++i) {
        if (!visited[i] && railways[city_index].count(i)) {
            dfs(visited, i, roads, railways, response);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, L, city1, city2;
    cin >> N >> K >> L;
    vector<set<int>> roads(K);
    vector<set<int>> railways(L);
    vector<int> response(N, 0);
    vector<bool> visited(N, false);

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

    for (size_t i = 0; i < visited.size(); ++i) {
        if (visited[i]) continue;

        dfs(visited, i, roads, railways, response);
    }

    for (size_t i = 0; i < response.size(); ++i) cout << response[i] << (i != response.size() - 1 ? " " : "\n");
}
