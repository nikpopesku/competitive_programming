#include <bits/stdc++.h>

using namespace std;

#define ll long long

void dfs(int city_index, vector<vector<int>>& adj, vector<int>& component, int comp_id) {
    component[city_index] = comp_id;
    for (int neighbor : adj[city_index]) {
        if (component[neighbor] == 0) {
            dfs(neighbor, adj, component, comp_id);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, L;
    cin >> N >> K >> L;

    vector<vector<int>> roads(N + 1);
    vector<vector<int>> railways(N + 1);

    for (int i = 0; i < K; ++i) {
        int city1, city2;
        cin >> city1 >> city2;
        roads[city1].push_back(city2);
        roads[city2].push_back(city1);
    }

    for (int i = 0; i < L; ++i) {
        int city1, city2;
        cin >> city1 >> city2;
        railways[city1].push_back(city2);
        railways[city2].push_back(city1);
    }

    vector<int> road_component(N + 1, 0);
    vector<int> railway_component(N + 1, 0);

    int road_comp_id = 1;
    for (int i = 1; i <= N; ++i) {
        if (road_component[i] == 0) {
            dfs(i, roads, road_component, road_comp_id++);
        }
    }

    int railway_comp_id = 1;
    for (int i = 1; i <= N; ++i) {
        if (railway_component[i] == 0) {
            dfs(i, railways, railway_component, railway_comp_id++);
        }
    }

    map<pair<int, int>, int> component_count;
    for (int i = 1; i <= N; ++i) {
        component_count[{road_component[i], railway_component[i]}]++;
    }

    for (int i = 1; i <= N; ++i) {
        cout << component_count[{road_component[i], railway_component[i]}] << (i == N ? "" : " ");
    }
    cout << endl;

    return 0;
}