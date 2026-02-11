#include<bits/stdc++.h>

using namespace std;

int dfs(const int elem, vector<vector<int>>& adj, set<int>& notvisited) {
    notvisited.erase(elem);

    for (auto nei: adj[elem]) {
        if (notvisited.contains(nei)) {
            dfs(nei, adj, notvisited);
        }
    }

    return elem;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, a, b;

    cin >> n >> m;

    vector adj(n+1, vector<int>());

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    set<int> notvisited;
    vector<pair<int, int>> response;
    int previous = 0;

    while (!notvisited.empty()) {
        int elem = *notvisited.begin();

        if (previous) {
            response.push_back({elem, previous});
        }

        previous = dfs(elem, adj, notvisited);
    }

    cout << response.size() << '\n';

    for (auto elem: response) {
        cout << elem.first << ' ' << elem.second << '\n';
    }
}