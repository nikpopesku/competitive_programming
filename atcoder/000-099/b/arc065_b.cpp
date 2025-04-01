#include<bits/stdc++.h>

using namespace std;

#define ll long long

void
dfs(vector<bool> &visited, int city_index, vector<set<int>> &roads, vector<set<int>> &railways,
    vector<int> &parents, vector<int> &parents_count, int &N, int &parent) {
    visited[city_index] = true;
    parents[city_index] = parent;
    ++parents_count[parent];

    for (auto it = roads[city_index].begin(); it != roads[city_index].end(); ++it) {
        if (!visited[*it] && railways[city_index].count(*it)) {
            parents[*it] = parent;
            dfs(visited, *it, roads, railways, parents, parents_count, N, parent);
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
    vector<int> parents(N + 1, 0);
    vector<int> parents_count(N + 1, 0);
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

        dfs(visited, i, roads, railways, parents, parents_count, N, i);
    }

    for (int i = 1; i <= N; ++i) cout << parents_count[parents[i]] << (i != N ? " " : "\n");
}
