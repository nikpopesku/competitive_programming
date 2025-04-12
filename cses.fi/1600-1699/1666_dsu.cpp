#include<bits/stdc++.h>

using namespace std;

int n, m, a, b;

int dfs(const int elem, set<int> &unvisited, vector<vector<int>> &roads) {
    unvisited.erase(elem);
    for (auto &road: roads[elem]) if (unvisited.contains(road)) dfs(road, unvisited, roads);

    return elem;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    vector<vector<int>> roads(n + 1);
    vector<pair<int, int>> response;
    vector<int> u(n);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }

    iota(u.begin(), u.end(), 1);
    set unvisited(u.begin(), u.end());
    int previous = 0;

    while (!unvisited.empty()) {
        int elem = *unvisited.begin();
        if (previous > 0) response.emplace_back(previous, elem);

        previous = dfs(elem, unvisited, roads);
    }


    cout << response.size() << "\n";
    for (auto & [fst, snd]: response) cout << fst << " " << snd << "\n";
}