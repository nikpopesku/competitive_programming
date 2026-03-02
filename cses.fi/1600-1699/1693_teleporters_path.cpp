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
    vector<int> indeg(n + 1, 0), outdeg(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        outdeg[a]++;
        indeg[b]++;
    }

    for (int i = 1; i <= n; ++i) {
        const int diff = outdeg[i] - indeg[i];
        if (i == 1 && diff != 1) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        if (i == n && diff != -1) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        if (i != 1 && i != n && diff != 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    vector<int> result;
    dfs(result, 1, adj);
    reverse(result.begin(), result.end());

    if (static_cast<int>(result.size()) != m + 1) {
        cout << "IMPOSSIBLE\n";

        return 0;
    }

    if (result[0] != 1 || result.back() != n) {
        cout << "IMPOSSIBLE\n";

        return 0;
    }

    for (const auto &i: result) {
        cout << i << ' ';
    }
}
