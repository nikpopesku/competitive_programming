#include <bits/stdc++.h>

using namespace std;

#define ll long long

void dfs(int index, vector<vector<int>> &adj_list, vector<int> &component, int parent) {
    component[index] = parent;

    for (auto &neighbor: adj_list[index]) {
        if (component[neighbor] == 0) {
            dfs(neighbor, adj_list, component, parent);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, L, val1, val2;
    cin >> N >> K >> L;

    vector<vector<int>> roads(N + 1);

    for (int i = 0; i < K; ++i) {
        cin >> val1 >> val2;

        roads[val1].push_back(val2);
        roads[val2].push_back(val1);
    }

    vector<vector<int>> railways(N + 1);

    for (int i = 0; i < K; ++i) {
        cin >> val1 >> val2;

        railways[val1].push_back(val2);
        railways[val2].push_back(val1);
    }

    vector<int> road_compoonent(N + 1, 0);
    vector<int> railway_compoonent(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        if (road_compoonent[i] == 0) {
            dfs(i, roads, road_compoonent, i);
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (railway_compoonent[i] == 0) {
            dfs(i, railways, railway_compoonent, i);
        }
    }

    map<pair<int, int>, int> mp;
    for (int i = 1; i <= N; ++i) {
        ++mp[{road_compoonent[i], railway_compoonent[i]}];
    }

    for (int i = 1; i <= N; ++i) cout << mp[{road_compoonent[i], railway_compoonent[i]}] << (i < N ? " " : "\n");
}