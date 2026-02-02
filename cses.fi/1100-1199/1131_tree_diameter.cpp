#include<bits/stdc++.h>

using namespace std;

int calc(int node, int parent, const vector<vector<int>> &adj, int &maxdiameter) {
    int best1 = 0;
    int best2 = 0;

    for (int nei : adj[node]) {
        if (nei == parent) {
            continue;
        }
        int depth = calc(nei, node, adj, maxdiameter) + 1;
        if (depth > best1) {
            best2 = best1;
            best1 = depth;
        } else if (depth > best2) {
            best2 = depth;
        }
    }

    maxdiameter = max(maxdiameter, best1 + best2);
    return best1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, u, v;
    cin >> n;
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n - 1; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int maxdiameter = 0;
    calc(1, 0, adj, maxdiameter);
    cout << maxdiameter << "\n";
}
