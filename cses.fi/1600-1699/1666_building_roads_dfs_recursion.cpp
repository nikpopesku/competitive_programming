#include<bits/stdc++.h>

using namespace std;

int dfs(const int elem, vector<vector<int> > &adj, set<int> &unvisited) {
    unvisited.erase(elem);

    for (auto nei: adj[elem]) {
        if (unvisited.contains(nei)) {
            dfs(nei, adj, unvisited);
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

    vector adj(n + 1, vector<int>());
    vector<int> node(n);
    iota(node.begin(), node.end(), 1);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    set<int> unvisited{node.begin(), node.end()};
    vector<pair<int, int> > response;
    int previous = 0;

    while (!unvisited.empty()) {
        int elem = *unvisited.begin();

        if (previous) {
            response.emplace_back(elem, previous);
        }

        previous = dfs(elem, adj, unvisited);
    }

    cout << response.size() << '\n';

    for (auto elem: response) {
        cout << elem.first << ' ' << elem.second << '\n';
    }
}
