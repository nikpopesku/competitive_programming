#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int> &result, const int node, vector<vector<int> > &adj) {
    while (!adj[node].empty()) {
        const int nei = adj[node].back();
        adj[node].pop_back();
        dfs(result, nei, adj);
    }

    result.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m;
    vector adj(n + 1, vector<int>());

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[b].push_back(a);
    }

    vector<int> result;
    dfs(result, n, adj);

    if (static_cast<int>(result.size()) != m + 1) {
        cout << "IMPOSSIBLE\n";

        return 0;
    }

    if (result.back() != n || result[0] != 1) {
        cout << "IMPOSSIBLE\n";

        return 0;
    }

    for (const auto &i: result) {
        cout << i << ' ';
    }
}
