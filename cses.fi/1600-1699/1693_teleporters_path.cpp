#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int>& response, int node, vector<vector<int>>& adj) {
    while (!adj[node].empty()) {
        auto e = adj[node].back();
        adj[node].pop_back();

        dfs(response, e, adj);
    }
    response.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m;
    vector adj(n + 1, vector<int>());
    vector<int> indegree(n + 1, 0);
    vector<int> outdegree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        ++outdegree[a];
        ++indegree[a];
    }

    vector<int> response;


    for (int i = 1; i <= n; ++i) {
        const int diff = outdegree[i] - indegree[i];
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

    if (response[0] != 1 || response.back() != n) {
        cout << "IMPOSSIBLE\n";

        return 0;
    }

    if (static_cast<int>(response.size()) != m + 1) {
        cout << "IMPOSSIBLE\n";

        return 0;
    }


    dfs(response, 1, adj);
    ranges::reverse(response);

    for (const auto &i: response) {
        cout << i << ' ';
    }
}
